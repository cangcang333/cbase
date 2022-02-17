# Big makefile


all: CBASE
	@echo
	@echo ===== All CBASE modules are Made =====
	@echo

clean: CLCBASE
	@echo
	@echo ===== All CBASE modules are Cleaned =====
	@echo


CBASE: makeCmn  \
       makeTools  \
       makeTest

CLCBASE: cleanCmn  \
	 cleanTools  \
	 cleanTest


# make

makeCmn:
	@cd cmn && make

makeTools:
	@cd tools && make

makeTest:
	@cd test && make
# clean

cleanCmn:
	@cd cmn && make clean

cleanTools:
	@cd tools && make clean

cleanTest:
	@cd test && make clean
