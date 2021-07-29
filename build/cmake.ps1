Remove-Item CMakeCache.txt -Force -ErrorAction 'silentlycontinue'
cmake .. -DCMAKE_GENERATOR="Unix Makefiles"