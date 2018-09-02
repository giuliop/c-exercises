/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
		int i, j;
		int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;

		for (i = 0; i < (N/4) * 4; i+=4) {
				for (j = 0; j < (M/8) * 8; j+=8) {
								t1 = A[i][j];
								t2 = A[i][j+1];
								t3 = A[i][j+2];
								t4 = A[i+1][j];
								t5 = A[i+1][j+1];
								t6 = A[i+1][j+2];
								t7 = A[i+2][j];
								t8 = A[i+2][j+1];
								t9 = A[i+2][j+2];
								t10 = A[i+3][j];

								B[j][i] = t1;
								B[j][i+1] = t4;
								B[j][i+2] = t7;
								B[j][i+3] = t10;
								B[j+1][i] = t2;
								B[j+1][i+1] = t5;
								B[j+1][i+2] = t8;
								B[j+2][i] = t3;
								B[j+2][i+1] = t6;
								B[j+2][i+2] = t9;

								t1 = A[i+3][j+1];
								t2 = A[i+3][j+2];
								B[j+1][i+3] = t1;
								B[j+2][i+3] = t2;

								t1 = A[i][j+3];
								t2 = A[i][j+4];
								t3 = A[i][j+5];
								t4 = A[i+1][j+3];
								t5 = A[i+1][j+4];
								t6 = A[i+1][j+5];
								t7 = A[i+2][j+3];
								t8 = A[i+2][j+4];
								t9 = A[i+2][j+5];
								t10 = A[i+3][j+3];

								B[j+3][i] = t1;
								B[j+3][i+1] = t4;
								B[j+3][i+2] = t7;
								B[j+3][i+3] = t10;
								B[j+4][i] = t2;
								B[j+4][i+1] = t5;
								B[j+4][i+2] = t8;
								B[j+5][i] = t3;
								B[j+5][i+1] = t6;
								B[j+5][i+2] = t9;

								t1 = A[i+3][j+4];
								t2 = A[i+3][j+5];
								B[j+4][i+3] = t1;
								B[j+5][i+3] = t2;

								t1 = A[i][j+6];
								t2 = A[i][j+7];
								t3 = A[i+1][j+6];
								t4 = A[i+1][j+7];
								t5 = A[i+2][j+6];
								t6 = A[i+2][j+7];
								t7 = A[i+3][j+6];
								t8 = A[i+3][j+7];

								B[j+6][i] = t1;
								B[j+6][i+1] = t3;
								B[j+6][i+2] = t5;
								B[j+6][i+3] = t7;
								B[j+7][i] = t2;
								B[j+7][i+1] = t4;
								B[j+7][i+2] = t6;
								B[j+7][i+3] = t8;
								if ((N == 67) && (M == 61)) {
										t1 = A[i][56];
										t2 = A[i][57];
										t3 = A[i][58];
										t4 = A[i][59];
										t5 = A[i][60];
										t6 = A[i+1][56];
										t7 = A[i+1][57];
										t8 = A[i+1][58];
										t9 = A[i+1][59];
										t10 = A[i+1][60];
										B[56][i] = t1;
										B[56][i+1] = t6;
										B[57][i] = t2;
										B[57][i+1] = t7;
										B[58][i] = t3;
										B[58][i+1] = t8;
										B[59][i] = t4;
										B[59][i+1] = t9;
										B[60][i] = t5;
										B[60][i+1] = t10;

										t1 = A[i+2][56];
										t2 = A[i+2][57];
										t3 = A[i+2][58];
										t4 = A[i+2][59];
										t5 = A[i+2][60];
										t6 = A[i+3][56];
										t7 = A[i+3][57];
										t8 = A[i+3][58];
										t9 = A[i+3][59];
										t10 = A[i+3][60];
										B[56][i+2] = t1;
										B[56][i+3] = t6;
										B[57][i+2] = t2;
										B[57][i+3] = t7;
										B[58][i+2] = t3;
										B[58][i+3] = t8;
										B[59][i+2] = t4;
										B[59][i+3] = t9;
										B[60][i+2] = t5;
										B[60][i+3] = t10;
								}
				}
		}
		if ((N == 67) && (M == 61)) {
				for (j = 0; j < 56; j+=8) {
								t1 = A[64][j];
								t2 = A[64][j+1];
								t3 = A[64][j+2];
								t4 = A[65][j];
								t5 = A[65][j+1];
								t6 = A[65][j+2];
								t7 = A[66][j];
								t8 = A[66][j+1];
								t9 = A[66][j+2];

								B[j][64] = t1;
								B[j][65] = t4;
								B[j][66] = t7;
								B[j+1][64] = t2;
								B[j+1][65] = t5;
								B[j+1][66] = t8;
								B[j+2][64] = t3;
								B[j+2][65] = t6;
								B[j+2][66] = t9;

								t1 = A[64][j+3];
								t2 = A[64][j+4];
								t3 = A[64][j+5];
								t4 = A[65][j+3];
								t5 = A[65][j+4];
								t6 = A[65][j+5];
								t7 = A[66][j+3];
								t8 = A[66][j+4];
								t9 = A[66][j+5];

								B[j+3][64] = t1;
								B[j+3][65] = t4;
								B[j+3][66] = t7;
								B[j+4][64] = t2;
								B[j+4][65] = t5;
								B[j+4][66] = t8;
								B[j+5][64] = t3;
								B[j+5][65] = t6;
								B[j+5][66] = t9;

								t1 = A[64][j+6];
								t2 = A[64][j+7];
								t3 = A[65][j+6];
								t4 = A[65][j+7];
								t5 = A[66][j+6];
								t6 = A[66][j+7];

								B[j+6][64] = t1;
								B[j+6][65] = t3;
								B[j+6][66] = t5;
								B[j+7][64] = t2;
								B[j+7][65] = t4;
								B[j+7][66] = t6;
				}
								t1 = A[64][56];
								t2 = A[64][57];
								t3 = A[64][58];
								t4 = A[64][59];
								t5 = A[64][60];
								t6 = A[65][56];
								t7 = A[65][57];
								t8 = A[65][58];
								t9 = A[65][59];
								t10 = A[65][60];
								B[56][64] = t1;
								B[56][65] = t6;
								B[57][64] = t2;
								B[57][65] = t7;
								B[58][64] = t3;
								B[58][65] = t8;
								B[59][64] = t4;
								B[59][65] = t9;
								B[60][64] = t5;
								B[60][65] = t10;
			
								t1 = A[66][56];
								t2 = A[66][57];
								t3 = A[66][58];
								t4 = A[66][59];
								t5 = A[66][60];
								B[56][66] = t1;
								B[57][66] = t2;
								B[58][66] = t3;
								B[59][66] = t4;
								B[60][66] = t5;
		}
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

char transpose_2x4_block_desc[] = "Transpose 2x4 block";
void transpose_2x4_block(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;
		int t1, t2, t3, t4, t5, t6, t7, t8; //, t9;

    for (i = 0; i < N; i+=2) {
				for (j = 0; j < M; j+=4) {
								t1 = A[i][j];
								t2 = A[i][j+1];
								t3 = A[i][j+2];
								t4 = A[i][j+3];
								t5 = A[i+1][j];
								t6 = A[i+1][j+1];
								t7 = A[i+1][j+2];
								t8 = A[i+1][j+3];

								B[j][i] = t1;
								B[j][i+1] = t5;
								B[j+1][i] = t2;
								B[j+1][i+1] = t6;
								B[j+2][i] = t3;
								B[j+2][i+1] = t7;
								B[j+3][i] = t4;
								B[j+3][i+1] = t8;
				}
		}
}

char transpose_2x2_block_desc[] = "Transpose 2x2 block";
void transpose_2x2_block(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;
		int t1, t2, t3, t4;

    for (i = 0; i < N; i+=2) {
				for (j = 0; j < M; j+=2) {
								t1 = A[i][j];
								t2 = A[i][j+1];
								t3 = A[i+1][j];
								t4 = A[i+1][j+1];

								B[j][i] = t1;
								B[j][i+1] = t3;
								B[j+1][i] = t2;
								B[j+1][i+1] = t4;
				}
		}
}

char transpose_2x3_2x5_block_desc[] = "Transpose 2x3_2x5 block";
void transpose_2x3_2x5_block(int M, int N, int A[N][M], int B[M][N])
{
		int i,j;
		int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;

    for (i = 0; i < N; i+=2) {
				for (j = 0; j < M; j+=8) {
								t1 = A[i][j];
								t2 = A[i][j+1];
								t3 = A[i][j+2];
								t4 = A[i+1][j];
								t5 = A[i+1][j+1];
								t6 = A[i+1][j+2];
								B[j][i] = t1;
								B[j][i+1] = t4;
								B[j+1][i] = t2;
								B[j+1][i+1] = t5;
								B[j+2][i] = t3;
								B[j+2][i+1] = t6;

								t1 = A[i][j+3];
								t2 = A[i][j+4];
								t3 = A[i][j+5];
								t4 = A[i][j+6];
								t5 = A[i][j+7];
								t6 = A[i+1][j+3];
								t7 = A[i+1][j+4];
								t8 = A[i+1][j+5];
								t9 = A[i+1][j+6];
								t10 = A[i+1][j+7];
								B[j+3][i] = t1;
								B[j+3][i+1] = t6;
								B[j+4][i] = t2;
								B[j+4][i+1] = t7;
								B[j+5][i] = t3;
								B[j+5][i+1] = t8;
								B[j+6][i] = t4;
								B[j+6][i+1] = t9;
								B[j+7][i] = t5;
								B[j+7][i+1] = t10;
				}
		}
}

char transpose_3x3_3x3_3x2_block_desc[] = "Transpose 3x3_3x3_3x2 block";
void transpose_3x3_3x3_3x2_block(int M, int N, int A[N][M], int B[M][N])
{
		int i,j;
		int t1, t2, t3, t4, t5, t6, t7, t8, t9;

    for (i = 0; i < 30; i+=3) {
				for (j = 0; j < M; j+=8) {
								t1 = A[i][j];
								t2 = A[i][j+1];
								t3 = A[i][j+2];
								t4 = A[i+1][j];
								t5 = A[i+1][j+1];
								t6 = A[i+1][j+2];
								t7 = A[i+2][j];
								t8 = A[i+2][j+1];
								t9 = A[i+2][j+2];
								B[j][i] = t1;
								B[j][i+1] = t4;
								B[j][i+2] = t7;
								B[j+1][i] = t2;
								B[j+1][i+1] = t5;
								B[j+1][i+2] = t8;
								B[j+2][i] = t3;
								B[j+2][i+1] = t6;
								B[j+2][i+2] = t9;

								t1 = A[i][j+3];
								t2 = A[i][j+4];
								t3 = A[i][j+5];
								t4 = A[i+1][j+3];
								t5 = A[i+1][j+4];
								t6 = A[i+1][j+5];
								t7 = A[i+2][j+3];
								t8 = A[i+2][j+4];
								t9 = A[i+2][j+5];
								B[j+3][i] = t1;
								B[j+3][i+1] = t4;
								B[j+3][i+2] = t7;
								B[j+4][i] = t2;
								B[j+4][i+1] = t5;
								B[j+4][i+2] = t8;
								B[j+5][i] = t3;
								B[j+5][i+1] = t6;
								B[j+5][i+2] = t9;

								t1 = A[i][j+6];
								t2 = A[i][j+7];
								t3 = A[i+1][j+6];
								t4 = A[i+1][j+7];
								t5 = A[i+2][j+6];
								t6 = A[i+2][j+7];
								B[j+6][i] = t1;
								B[j+6][i+1] = t3;
								B[j+6][i+2] = t5;
								B[j+7][i] = t2;
								B[j+7][i+1] = t4;
								B[j+7][i+2] = t6;
				}
		}
    for (i = 30; i < N; i+=2) {
				for (j = 0; j < M; j+=4) {
								t1 = A[i][j];
								t2 = A[i][j+1];
								t3 = A[i][j+2];
								t4 = A[i][j+3];
								t5 = A[i+1][j];
								t6 = A[i+1][j+1];
								t7 = A[i+1][j+2];
								t8 = A[i+1][j+3];

								B[j][i] = t1;
								B[j][i+1] = t5;
								B[j+1][i] = t2;
								B[j+1][i+1] = t6;
								B[j+2][i] = t3;
								B[j+2][i+1] = t7;
								B[j+3][i] = t4;
								B[j+3][i+1] = t8;
				}
		}
}

char transpose_4x3_3_2_block_desc[] = "Transpose 4x3_3_2 block";
void transpose_4x3_3_2_block(int M, int N, int A[N][M], int B[M][N])
{
		int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;

    for (int i = 0; i < (N/4) * 4; i+=4) {
				for (int j = 0; j < (M/8) * 8; j+=8) {
								t1 = A[i][j];
								t2 = A[i][j+1];
								t3 = A[i][j+2];
								t4 = A[i+1][j];
								t5 = A[i+1][j+1];
								t6 = A[i+1][j+2];
								t7 = A[i+2][j];
								t8 = A[i+2][j+1];
								t9 = A[i+2][j+2];
								t10 = A[i+3][j];

								B[j][i] = t1;
								B[j][i+1] = t4;
								B[j][i+2] = t7;
								B[j][i+3] = t10;
								B[j+1][i] = t2;
								B[j+1][i+1] = t5;
								B[j+1][i+2] = t8;
								B[j+2][i] = t3;
								B[j+2][i+1] = t6;
								B[j+2][i+2] = t9;

								t1 = A[i+3][j+1];
								t2 = A[i+3][j+2];
								B[j+1][i+3] = t1;
								B[j+2][i+3] = t2;

								t1 = A[i][j+3];
								t2 = A[i][j+4];
								t3 = A[i][j+5];
								t4 = A[i+1][j+3];
								t5 = A[i+1][j+4];
								t6 = A[i+1][j+5];
								t7 = A[i+2][j+3];
								t8 = A[i+2][j+4];
								t9 = A[i+2][j+5];
								t10 = A[i+3][j+3];

								B[j+3][i] = t1;
								B[j+3][i+1] = t4;
								B[j+3][i+2] = t7;
								B[j+3][i+3] = t10;
								B[j+4][i] = t2;
								B[j+4][i+1] = t5;
								B[j+4][i+2] = t8;
								B[j+5][i] = t3;
								B[j+5][i+1] = t6;
								B[j+5][i+2] = t9;

								t1 = A[i+3][j+4];
								t2 = A[i+3][j+5];
								B[j+4][i+3] = t1;
								B[j+5][i+3] = t2;

								t1 = A[i][j+6];
								t2 = A[i][j+7];
								t3 = A[i+1][j+6];
								t4 = A[i+1][j+7];
								t5 = A[i+2][j+6];
								t6 = A[i+2][j+7];
								t7 = A[i+3][j+6];
								t8 = A[i+3][j+7];

								B[j+6][i] = t1;
								B[j+6][i+1] = t3;
								B[j+6][i+2] = t5;
								B[j+6][i+3] = t7;
								B[j+7][i] = t2;
								B[j+7][i+1] = t4;
								B[j+7][i+2] = t6;
								B[j+7][i+3] = t8;
				}
		}
}
/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
		registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
	/*registerTransFunction(transpose_3x3_3x3_3x2_block, transpose_3x3_3x3_3x2_block_desc); */
	/*registerTransFunction(transpose_2x3_2x5_block, transpose_2x3_2x5_block_desc); */
	/*registerTransFunction(transpose_4x3_3_2_block, transpose_4x3_3_2_block_desc); */
	/*registerTransFunction(transpose_2x4_block, transpose_2x4_block_desc); */
	/*registerTransFunction(transpose_2x2_block, transpose_2x2_block_desc); */

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

