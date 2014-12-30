all: makelib makebin
	cp -f ./libtest/test .

clean: cleanlib cleanbin
	rm -rf test

makelib:
	make -C ./bigint 

makebin:
	make -C ./libtest 

cleanlib:
	make -C ./bigint clean 

cleanbin:
	make -C ./libtest clean


