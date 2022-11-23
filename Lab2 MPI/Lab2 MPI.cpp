// 10. О мудрецах. Два мудреца рассуждают, говоря строго по очереди(MPI). 
// Однако из-за увлеченности, они слышат и повторяют вслух(на экран) лишь каждое второе сообщение, сказанное другим.

#include <iostream>
#include <mpi.h>

#define TIME_TALK 10

int main(int argc, char** argv) {
	int rank, size, len; 
	char proc_name[MPI_MAX_PROCESSOR_NAME];
	bool Check0 = true;
	bool Check1 = true;
	MPI_Status status;

	MPI_Init(&argc, &argv); 
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Get_processor_name(proc_name, &len);

	printf("Proc name %s, Rank %d, Size %d\n\n", proc_name, rank, size);

		if (rank == 0) {
			char thought[] = "You Shall Not Pass!";
			char receiver[50];
			int n = 0;

			while (n < TIME_TALK) {
				MPI_Send(&thought, 50, MPI_CHAR, 1, 5, MPI_COMM_WORLD);
				MPI_Recv(&receiver, 50, MPI_CHAR, 1, 5, MPI_COMM_WORLD, &status);

				if (Check0 == true) {
					Check0 = false;
					printf("The wise man %d says: %s\n\n", rank, receiver);
					//std::cout << "The wise man " << rank << " says: " << speech1 << "\n\n";
				}
				else if (Check0 == false) {
					Check0 = true;
				}
				n++;
			}
		}

		if (rank == 1) {
			char thought[] = "I love the smell of napalm in the morning.";
			char receiver[50];
			int n = 0;

			while (n < TIME_TALK) {
				MPI_Recv(&receiver, 50, MPI_CHAR, 0, 5, MPI_COMM_WORLD, &status);
				MPI_Send(&thought, 50, MPI_CHAR, 0, 5, MPI_COMM_WORLD);
				if (Check1 == true) {
					Check1 = false;
					printf("The wise man %d says: %s\n\n", rank, receiver);
					//std::cout << "The wise man " << rank << " says: " << speech0 << "\n\n";
				}
				else if (Check1 == false) {
					Check1 = true;
				}
				n++;
			}
		}

	MPI_Finalize();
}
