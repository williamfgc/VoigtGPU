

CCOMPILER=gcc
CUDACOMPILER=nvcc

CFLAGS    = -lstdc++ -shared -lcudart -g
LDFLAGS   = -L/usr/local/cuda/lib64
CUDAFLAGS = -c -m64 -Xcompiler -fPIC

BASENAME=Voigt_GPU
LIBRARY=lib$(BASENAME).so

all:  $(LIBRARY)

$(LIBRARY): $(BASENAME)_Kernels.o $(BASENAME)_Functions.o 
			$(CCOMPILER) $(BASENAME)_Kernels.o $(BASENAME)_Functions.o $(CFLAGS) -o $(LIBRARY) $(LDFLAGS)
                
$(BASENAME)_Functions.o:	$(BASENAME)_Functions.cu $(BASENAME)_Kernels.o
							$(CUDACOMPILER) $(CUDAFLAGS) $(BASENAME)_Functions.cu -o $(BASENAME)_Functions.o
                           
$(BASENAME)_Kernels.o:	$(BASENAME)_Kernels.cu     
						$(CUDACOMPILER) $(CUDAFLAGS) $(BASENAME)_Kernels.cu -o $(BASENAME)_Kernels.o			

clean:	
		rm -f *.o
		rm -f *.so
