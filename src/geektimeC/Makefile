#/*
# *  Copyright 2003, China Union Pay Co., Ltd.  All right reserved.
# *
# *  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF CHINA UNION PAY CO.,
# *  LTD.  THE CONTENTS OF THIS FILE MAY NOT BE DISCLOSED TO THIRD
# *  PARTIES, COPIED OR DUPLICATED IN ANY FORM, IN WHOLE OR IN PART,
# *  WITHOUT THE PRIOR WRITTEN PERMISSION OF CHINA UNION PAY CO., LTD.
# *
# *  $Id: Makefile,v 1.13 2017/11/03 09:06:31 byshen Exp $
# *
# *
# *
# *  Edit History:
# *
# */


#-----------------------------------------------------
# include common define
#-----------------------------------------------------
include ${APP_DIR}/src/Makefile.cbase

#-----------------------------------------------------
# collection define
#-----------------------------------------------------

EXEFILE =  $(BIN_DIR)/01_core_syntax  \
	   $(BIN_DIR)/02_data_store_1  \
	   $(BIN_DIR)/02_data_store_2

01CoreSyntax_src = $(SRC_DIR)/geektimeC/01_core_syntax.c
02DataStore1_src = $(SRC_DIR)/geektimeC/02_data_store_1.c
02DataStore2_src = $(SRC_DIR)/geektimeC/02_data_store_2.c

#-----------------------------------------------------
# taget define
#-----------------------------------------------------
all: ${EXEFILE}
	@echo geektimeC is up to date.

clean:
	@echo Clean geekTimeC ...
	@rm -rf $(EXEFILE)
	@echo Clean geekTimeC Completed!


#-----------------------------------------------------
# rules define
#-----------------------------------------------------
${BIN_DIR}/01_core_syntax: $(01CoreSyntax_src)
	@echo Compling program `basename $@`...
	@$(CC) -o $@ $(01CoreSyntax_src)

${BIN_DIR}/02_data_store_1: $(02DataStore1_src)
	@echo Compling program `basename $@`...
	@$(CC) -o $@ $(02DataStore1_src)

${BIN_DIR}/02_data_store_2: $(02DataStore2_src)
	@echo Compling program `basename $@`...
	@$(CC) -o $@ $(02DataStore2_src)
