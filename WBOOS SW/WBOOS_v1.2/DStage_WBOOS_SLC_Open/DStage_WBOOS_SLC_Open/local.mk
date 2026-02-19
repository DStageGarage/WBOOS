#------------------------------------------------------------------------------
# LOCAL.MK - Allows you to customize the build/Make process for a particular 
#   PSoC Designer project.  The information you enter in this file is governed 
#   by MAKE.  It is recommended that you read about MAKE in the 
#   PSoC Designer/Documents/Supporting Documents/Make.PDF.  It is also 
#   recommended that you set the Options >> Builder >> Enable verbose
#   build messages, so that you can view the impact of the changes caused
#   by actions in this file.
#
#   There are no dependencies in the primary Make process (e.g. ...\tools\Makefile)
#   associated with this file.  Therefore, if you build the project, after saving 
#   changed information in this file, you may not get the changes you expected.
#   You can "touch" a file before you build to allow changes in this file to 
#   take effect.
#
#   Example use:
#
# To Enable the 24MHZ alignment option in ImageCraft
#CODECOMPRESSOR:=$(CODECOMPRESSOR) -z 
#
#
# To enable floating point 
#CODECOMPRESSOR:=$(CODECOMPRESSOR) -lfpm8c 