#ifndef AJACENCYMATRIX_H
#define AJACENCYMATRIX_H

#define T true
#define F false

bool aMatrix[9][9]{//   A  B  C  D  E  F  G  H  I
						F, T, F, T, T, F, F, F, F, // A
						F, F, F, F, T, F, F, F, F, // B
						F, F, F, F, F, F, F, F, F, // C
						F, F, F, F, F, T, F, F, F, // D
						F, F, F, F, F, T, F, T, F, // E
						F, F, F, F, F, F, F, T, F, // F
						F, F, F, F, F, F, F, T, F, // G
						F, F, F, F, F, F, F, F, T, // H
						F, F, F, F, F, T, F, F, F  // I
				  };
	
#endif

