
#-----------------------------------------------------
# include common define
#-----------------------------------------------------
include ${APP_DIR}/src/Makefile.cbase

#-----------------------------------------------------
# collection define
#-----------------------------------------------------

EXECFILE    = ${LIB_DIR}/libCmn.a                  


cmnBase_obj = ${OBJ_DIR}/cmnStrTrim.o

#-----------------------------------------------------
# taget define
#-----------------------------------------------------
all: $(EXECFILE)
	@echo CMN is up to date.

clean:
	@echo Clean CMN ...
	@rm -rf $(EXECFILE)
	@rm -rf $(cmnBase_obj)
	@echo Clean CMN Completed!

#-----------------------------------------------------
# rules define
#-----------------------------------------------------

${OBJ_DIR}/cmnStrTrim.o : cmnStrTrim.c
	@echo Compiling program `basename $?` ...
	@$(CC) $(CFLAGS2)  $? -o $@


#-----------------------------------------------------
# dependence define
#-----------------------------------------------------
${LIB_DIR}/libCmn.a: $(cmnBase_obj)
	@echo Linking `basename $@` ...
	@$(AR) -r $@ $(cmnBase_obj) 2>/dev/null

