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
# *    2014Äê5ÔÂ6ÈÕ - Created by xfhu.
# */


#-----------------------------------------------------
# include common define
#-----------------------------------------------------
include ${APP_DIR}/src/Makefile.cbase

#-----------------------------------------------------
# collection define
#-----------------------------------------------------

EXEFILE =  $(BIN_DIR)/filePassTest

filePassTest_src = $(SRC_DIR)/test/filePassTest.c

#-----------------------------------------------------
# taget define
#-----------------------------------------------------
all: ${EXEFILE}
	@echo TOOL is up to date.

clean:
	@echo Clean TOOL ...
	@rm -rf $(EXEFILE)
	@echo Clean TOOL Completed!


#-----------------------------------------------------
# rules define
#-----------------------------------------------------
${BIN_DIR}/filePassTest : $(filePassTest_src)
	@echo Compling program `basename $@`...
	@$(CC) -o $@ $(filePassTest_src) $(INCL)

