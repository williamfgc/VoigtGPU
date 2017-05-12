


CUDACOMPILER=nvcc 
#LDFLAGS   = -L/usr/local/cuda/lib64 -lstdc++ -shared -lcudart
LDFLAGS   = -L/usr/local/cuda/lib64 -lstdc++ -lcudart
CUDAFLAGS = -O0 -g -std=c++11 -m64 -Xcompiler -fPIC

BASENAME=VoigtKernelsTest

all:  $(BASENAME).cu
	$(CUDACOMPILER) $(CUDAFLAGS) $(BASENAME).cu -o $(BASENAME).exe $(LDFLAGS)     
	
clean:
	rm $(BASENAME).exe