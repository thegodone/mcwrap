#### main

/*
*
* This file was auto-generated by MCWRAP
* https://github.com/magland/mcwrap
*
* You should not edit this file.
* You might not even want to read it.
* 
*/ 

#include "mex.h"

@foreach header
#include "../$header$"
@end foreach header

//====================================================================
//====================================================================
        
int mcwrap_size(const mxArray *X,int j);

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

      //mexPrintf("test A\n");
//   Check the number of inputs/outputs
      if (nlhs==0) nlhs=1;
      if (nrhs!=$num_inputs$)
         mexErrMsgTxt("Incorrect number of inputs"); 
      else if (nlhs>$num_outputs$)
         mexErrMsgTxt ("Too many outputs.");

      // mexPrintf("test A.2\n");
//    Setup the set inputs
@foreach set_input
    @if $ptype$=int
        ^template fsetup_set_input_int
    @end if $ptype$=int
    @if $ptype$=double
        ^template fsetup_set_input_double
    @end if $ptype$=double
@end foreach set_input

      //mexPrintf("test B\n");
//    Setup the inputs
@foreach input
    @if $ptype$=int
        ^template fsetup_input_int
    @end if $ptype$=int
    @if $ptype$=double
        ^template fsetup_input_double
    @end if $ptype$=double
    @if $ptype$=double*
        ^template fsetup_input_double_array$underscore_complex$
    @end if $ptype$=double*
    @if $ptype$=int*
        ^template fsetup_input_int_array
    @end if $ptype$=int*
@end foreach input
    
      //mexPrintf("test C\n");
//    Setup the outputs
@foreach output
    @if $ptype$=int
        ^template fsetup_output_int
    @end if $ptype$=int
    @if $ptype$=double
        ^template fsetup_output_double
    @end if $ptype$=double
    @if $ptype$=double*
        ^template fsetup_output_double_array$underscore_complex$
    @end if $ptype$=double*
    @if $ptype$=int*
        ^template fsetup_output_int_array
    @end if $ptype$=int*
@end foreach output

    
      //mexPrintf("test D\n");
//    Run the subroutine
        $function_name$(
$arguments$
        );
   
      //mexPrintf("test E\n");
//    Free the inputs
@foreach input
    @if $ptype$=double*
        ^template ffree_input_double_array$underscore_complex$
    @end if $ptype$=double*
    @if $ptype$=int*
        ^template ffree_input_int_array
    @end if $ptype$=int*
@end foreach input

      //mexPrintf("test F\n");
//    Set the outputs
@foreach output
    @if $ptype$=int
        ^template fset_output_int
    @end if $ptype$=int
    @if $ptype$=double
        ^template fset_output_double
    @end if $ptype$=double
    @if $ptype$=double*
        ^template fset_output_double_array$underscore_complex$
    @end if $ptype$=double*
    @if $ptype$=int*
        ^template fset_output_int_array
    @end if $ptype$=int*
@end foreach output

      //mexPrintf("test G\n");

/**** We are done *******/
}

int mcwrap_size(const mxArray *X,int j) {
    mwSize numdims=mxGetNumberOfDimensions(X);
    if ((j<1)||(j>numdims)) return 1;
    const mwSize *dims2=mxGetDimensions(X);
    return dims2[j-1];
}

        //$pname$
//CC Scalar output not yet supported!

#### ffree_input_double_array

        //$pname$

#### ffree_input_double_array_complex

        //$pname$
        free(input_$pname$);

#### ffree_input_int_array

        //$pname$
        free(input_$pname$);

#### fset_output_double

        //$pname$
//CC Scalar outputs not yet supported

#### fset_output_double_array

        //$pname$

#### fset_output_double_array_complex

        //$pname$
        if ($pindex$<=nlhs) {
            for (long ii=0; ii<$total_size$; ii++) {
                output_$pname$_re[ii]=output_$pname$[ii*2];
                output_$pname$_im[ii]=output_$pname$[ii*2+1];
            }
        }
        free(output_$pname$);

#### fset_output_int_array

        //$pname$
        if ($pindex$<=nlhs) {
            for (long ii=0; ii<$total_size$; ii++) {
                output_$pname$_double[ii]=output_$pname$[ii];
            }
        }
        free(output_$pname$_double);

#### fset_output_int

//CC Scalar outputs not yet supported

#### fsetup_input_double

        //$pname$
        double *p_input_$pname$=mxGetPr(prhs[$pindex$-1]);
        double input_$pname$=p_input_$pname$[0];

#### fsetup_input_int

        //$pname$
        double *p_input_$pname$=mxGetPr(prhs[$pindex$-1]);
        int input_$pname$=(int)p_input_$pname$[0];

#### fsetup_input_double_array

        //$pname$
        ^template fsetup_check_dimensions
        double *input_$pname$=mxGetPr(prhs[$pindex$-1]);
        
#### fsetup_input_double_array_complex

        //$pname$
        ^template fsetup_check_dimensions
        double *input_$pname$_re=mxGetPr(prhs[$pindex$-1]);
        double *input_$pname$_im=mxGetPi(prhs[$pindex$-1]);
        double *input_$pname$=(double *)malloc(sizeof(double)*($total_size$*2));
        for (long ii=0; ii<$total_size$; ii++) {
            input_$pname$[ii*2]=input_$pname$_re[ii];
            if (input_$pname$_im) {
                input_$pname$[ii*2+1]=input_$pname$_im[ii];
            }
            else {
                input_$pname$[ii*2+1]=0;    
            }
        }

#### fsetup_input_int_array

        //$pname$
        ^template fsetup_check_dimensions
        double *input_$pname$_double=mxGetPr(prhs[$pindex$-1]);
        int *input_$pname$=(int *)malloc(sizeof(int)*($total_size$));
        for (long ii=0; ii<$total_size$; ii++) {;
            input_$pname$[ii]=(int)(input_$pname$_double[ii])
        }
        

#### fsetup_check_dimensions

        //Check that we have the correct dimensions!
        {
            int numdims=mxGetNumberOfDimensions(prhs[$pindex$-1]);
            if (numdims!=$numdims$) {
              mexErrMsgTxt("Incorrect number of dimensions in input: $pname$");
            }
            const mwSize *dims2=mxGetDimensions(prhs[$pindex$-1]);
            int dims[]={ $dimensions$ };
            for (long ii=0; ii<numdims; ii++) {
              if (dims[ii]!=dims2[ii]) {
                mexErrMsgTxt("Incorrect size of input: $pname$");
              }
            }
        }

#### fsetup_output_double

        //$pname$
//CC Scalar output not yet supported

#### fsetup_output_double_array

        //$pname$
        double *output_$pname$;
        if ($pindex$<=nlhs) {
            ^template check_dimensions_valid
            mwSize dims[]={ $dimensions$ };
            plhs[$pindex$-1]=mxCreateNumericArray($numdims$,dims,mxDOUBLE_CLASS,mxREAL);
            output_$pname$=mxGetPr(plhs[$pindex$-1]);
        }

#### fsetup_output_double_array_complex

        //$pname$
        double *output_$pname$_re;
        double *output_$pname$_im;
        double *output_$pname$;
        if ($pindex$<=nlhs) {
            ^template check_dimensions_valid
            mwSize dims[]={ $dimensions$ };
            plhs[$pindex$-1]=mxCreateNumericArray($numdims$,dims,mxDOUBLE_CLASS,mxCOMPLEX);
            output_$pname$_re=mxGetPr(plhs[$pindex$-1]);
            output_$pname$_im=mxGetPi(plhs[$pindex$-1]);
        }
        output_$pname$=(double *)malloc(sizeof(double)*($total_size$)*2);

#### fsetup_output_int_array

        //$pname$
        double *output_$pname$_double;
        int *output_$pname$;
        if ($pindex$<=nlhs) {
            mwSize dims[]={ $dimensions$ };
            plhs[$pindex$-1]=mxCreateNumericArray($numdims$,dims,mxDOUBLE_CLASS,mxREAL);
            output_$pname$_double=mxGetPr(plhs[$pindex$-1]);
        }
        output_$pname$=(int *)malloc(sizeof(int)*($total_size$));

#### check_dimensions_valid

        if (($numdims$<1)||($numdims$>20)) {
          mexErrMsgTxt("Bad number of dimensions for my taste: $numdims$"); 
        }
        {
            int dims2[]={ $dimensions$ };
            for (long ii=0; ii<$numdims$; ii++) {
                if ((dims2[ii]<1)||(dims2[ii]>10000000000.0)) {
                  mexErrMsgTxt ("Bad array size for my taste: $dimensions$"); 
                }
            }
        }
        
#### fsetup_output_int

//CC Scalar output not yet supported

#### fsetup_set_input_double

        //$pname$
        $ptype$ input_$pname$=$set_value$;

#### fsetup_set_input_int

        //$pname$
        $ptype$ input_$pname$=(int)($set_value$);


#### end

