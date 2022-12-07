// Напишите программу с использованием MPI, моделирующую ситуацию: 
// есть 100 зайцев (процессы), и у каждого зайца в закромах есть от 1 до 4 килограммов моркови.
// Происходит продразверстка, и заяц - председатель по одному опрашивает каждого зайца, сколько у того припасено моркови.
// Заяц может сказать правду с вероятностью 20 %, и занизить в ответе количество моркови с вероятностью 80%.
// Затем председатель объявляет, сколько килограммов моркови собрано при продразверстке.

#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
	int rank, size, len;
	char proc_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Get_processor_name(proc_name, &len);

	printf("Proc name %s, Rank %d, Size %d\n\n", proc_name, rank, size);
	srand((unsigned int)time(0));

	if (rank == 0) {
		int rnd = 0, n = 0;
		char sender[100] = "";
		char receiver[100];
		bool Check = true;

		while (n < TIME_TALK) {
			rnd = rand() % 3;
			switch (rnd)
			{
			case 0:	strcpy(sender, "You Shall Not Pass!"); break;
			case 1: strcpy(sender, "Tell me, friend, when did Saruman the Wise abandon reason for madness?"); break;
			case 2: strcpy(sender, "But we still have time.Time enough to counter Sauron if we act quickly."); break;
			default: break;
			}
			MPI_Send(&sender, 100, MPI_CHAR, 1, 5, MPI_COMM_WORLD);
			MPI_Recv(&receiver, 100, MPI_CHAR, 1, 5, MPI_COMM_WORLD, &status);

			if (Check == true) {
				Check = false;
				printf("The wise man %d says: %s\n\n", rank, receiver);
			}
			else if (Check == false) {
				Check = true;
			}
			n++;
		}
	}

	if (rank > 0) {
		int rnd = 0, n = 0;
		char sender[100] = "";
		char receiver[100];
		bool Check = true;

		while (n < TIME_TALK) {
			rnd = rand() % 4;
			switch (rnd)
			{
			case 0:	strcpy(sender, "We must join with Him, Gandalf. We must join with Sauron. It would be wise, my friend."); break;
			case 1: strcpy(sender, "Against the power of Mordor there can be no victory."); break;
			case 2: strcpy(sender, "Time? What time do you think we have?"); break;
			case 3:	strcpy(sender, "I gave you the chance of aiding me willingly, but you have elected the way of pain!"); break;
			default: break;
			}
			MPI_Recv(&receiver, 100, MPI_CHAR, 0, 5, MPI_COMM_WORLD, &status);
			MPI_Send(&sender, 100, MPI_CHAR, 0, 5, MPI_COMM_WORLD);
			if (Check == true) {
				Check = false;
				printf("The wise man %d says: %s\n\n", rank, receiver);
			}
			else if (Check == false) {
				Check = true;
			}
			n++;
		}
	}

	MPI_Finalize();
}
