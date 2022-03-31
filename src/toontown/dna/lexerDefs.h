// Filename: lexerDefs.h
// Created by:  shochet (25May00)
//
////////////////////////////////////////////////////////////////////

#ifndef LEXERDEFS_H
#define LEXERDEFS_H

#include "toontownbase.h"

#include <string>

void dna_init_lexer(std::istream &in, std::ostream &err, const std::string &filename);
int dna_error_count();
int dna_warning_count();

void dnayyerror(const std::string &msg);
void dnayyerror(std::ostringstream &strm);

void dnayywarning(const std::string &msg);
void dnayywarning(std::ostringstream &strm);

int dnayylex();

// we never read .dna files from the terminal, always from files
#define YY_NEVER_INTERACTIVE 1

#endif
