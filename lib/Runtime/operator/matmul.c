#include <onnc/Runtime/operator/matmul.h>

#include <stdint.h>
#include <stdbool.h>

static int con(
	int * meofarr, int ndim, const int * restrict dims
){
	int mul = 1, res = 0 ;
	for(int i = ndim - 1 ; i >= 0 ; --i){
		res += meofarr[i] * mul ;
		mul *= dims[i] ;
	}
	return res ;
}
static void Enu(
	const float * restrict A,
	const int * restrict A_dims,
	const float * restrict B,
	const int * restrict B_dims,
	float * restrict C,
	int C_ndim, const int * restrict C_dims,
	int * meofarr, int idx,
	int num
){
	if( idx == C_ndim ){
		int ou_idx = con( meofarr, C_ndim, C_dims );
		C[ ou_idx ] = 0 ;
		int _1 = meofarr[ C_ndim-1 ] ;
		int _2 = meofarr[ C_ndim-2 ] ;
		for(int i = 0 ; i < num ; ++i){
			meofarr[ C_ndim-1 ] =  i;
			int A_idx = con( meofarr, C_ndim, A_dims );
			meofarr[ C_ndim-1 ] = _1;
			meofarr[ C_ndim-2 ] =  i;
			int B_idx = con( meofarr, C_ndim, B_dims );
			C[ ou_idx ] += A[ A_idx ] * B[ B_idx ];
			meofarr[ C_ndim-1 ] = _1;
			meofarr[ C_ndim-2 ] = _2;
		}
	} else {
		for(int i = 0 ; i < C_dims[idx] ; ++i){
			meofarr[ idx ] = i ;
			Enu(
				A,
				A_dims,
				B,
				B_dims,
				C,
				C_ndim, C_dims,
				meofarr, idx+1,
				num
			);
		}
	}
}

void ONNC_RUNTIME_matmul_float(
  void * restrict onnc_runtime_context
  ,const float * restrict input_A
  ,int input_A_ndim, const int * restrict input_A_dims
  ,const float * restrict input_B
  ,int input_B_ndim, const int * restrict input_B_dims
  ,float * restrict output_Y
  ,int output_Y_ndim, const int * restrict output_Y_dims
  
) {
	int meofarr[output_Y_ndim];
	Enu(
		input_A,
		input_A_dims,
		input_B,
		input_B_dims,
		output_Y,
		output_Y_ndim, output_Y_dims,
		meofarr, 0,
		input_A_dims[ input_A_ndim - 1 ]
	);
}
