mkdir -p proto; cp -pf "ackermann.c" "ackermann1.c" proto 
"/cygdrive/c/NewRVT/Debug/rvt"  -mt -fuf rv_pe.fuf "ackermann.c" "ackermann1.c" >& out 
echo -n $status > .status
