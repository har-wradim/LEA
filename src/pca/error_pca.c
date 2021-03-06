/*
    sNMF, file: error_pca.c
    Copyright (C) 2013 François Mathieu, Eric Frichot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <R.h>


#include "error_pca.h"
#include "print_pca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print_error_pca

void print_error_pca(char* msg, char*file) 
{
	Rprintf("\n");

	// error message depends on the error type
	if (!strcmp(msg,"cmd")) {
	        Rprintf("ERROR: no value for %s.\n\n",file);
		print_help_pca();
	} else if (!strcmp(msg,"option")) {
	        Rprintf("ERROR: the following option is mandatory: %s.\n\n",file);
		print_help_pca();
	} else if (!strcmp(msg,"missing")) {
	        Rprintf("ERROR: one of the following options is missing or not positive: -K, -m  \n\n");
		print_help_pca();
	} else if (!strcmp(msg,"basic")) {
	        Rprintf("ERROR: the command is not written correctly.\n\n");
		print_help_pca();
	} else if (!strcmp(msg,"specific")) {
	        Rprintf("ERROR: %s.\n\n",file);
		print_help_pca();
	} else {
		Rprintf("ERROR: Internal error.\n");
	}

	Rprintf("\n");
	error(NULL); 

}
