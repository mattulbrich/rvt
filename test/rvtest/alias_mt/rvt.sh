mkdir -p proto; cp -pf "alias.c" "alias1.c" proto 
"/cygdrive/c/NewRVT/debug/rv.exe"  -unitrv -mt "alias.c" "alias1.c" >& out 
echo -n $status > .status
