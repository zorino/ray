source ../0parameters.sh
source ../0sim8-parameters.sh

mpirun -np 1 Ray -p $left $right $length $sd &> log1
print-latex.sh $ref Ray-Contigs.fasta Ray
