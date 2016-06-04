
/*  o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o

    CTool Library
    Copyright (C) 1998-2001	Shaun Flisakowski

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 1, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o  */
/*  o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
    o+
    o+     File:         stemnt.cpp
    o+
    o+     Programmer:   Shaun Flisakowski
    o+     Date:         Aug 9, 1998
    o+
    o+     A high-level view of statements.
    o+
    o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o  */

#include <cstring>
#include <vector>
#include <cassert>

#include <ctool/stemnt.h>
#include <ctool/symbol.h>
#include <ctool/decl.h>
#include <ctool/project.h>

#include "gram.h"

//#define PRINT_LOCATION

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
//  indent - 2 spaces per level.
void
indent(std::ostream& out, int level)
{
    if (level > 0)
    {
        for (int j=level; j > 0; j--)
          out << "  ";
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
printNull(std::ostream& out, int level)
{
    indent(out,level);
    out << ";\n";
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
printBlock(std::ostream& out, int level, Statement *block)
{
    if (block == NULL)
        printNull(out,level+1);
    else if (block->isBlock())
        block->print(out,level);
    else
    {
        block->print(out,level+1);
        if (block->needSemicolon())
            out << ";";
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
ReverseList( Statement* sList )
{
    Statement*    head = NULL;

    while (sList != NULL)
    {
        Statement*    ste = sList;

        sList = sList->next;

        ste->next = head;
        head = ste;
    }

    return head; 
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Label::Label( LabelType labelType )
{
    type  = labelType;
    begin = NULL;
    end   = NULL;
}   

Label::Label( Expression *expr )
{
    type = LT_Case;
    begin = expr;
    end   = NULL;
}   

Label::Label( Expression *_begin, Expression *_end )
{
    type = LT_CaseRange;
    begin = _begin;
    end   = _end;
}

Label::Label( Symbol *sym )
{
    type = LT_Goto;
    name = sym;
    end   = NULL;
}   

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Label::~Label()
{
    switch (type)
    {
        case LT_Case:
        case LT_CaseRange:
            delete begin;
            delete end;
            break;

        case LT_Goto:
            delete name;
            break;

        default:
            break;
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Label*
Label::dup() const
{
    Label *ret = this ? dup0() : NULL;
    return ret;
}

Label*
Label::dup0() const
{
    Label *ret = new Label(type);

    switch (type)
    {
      default:
      case LT_None:
      case LT_Default:
        break;

      case LT_CaseRange:
        ret->end = end->dup();
      case LT_Case:
        ret->begin = begin->dup();
        break;

      case LT_Goto:
        ret->name = name->dup();
        break;
    }
    
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Label::print(std::ostream& out, int level) const
{
    indent(out,level-1);

    switch (type)
    {
        case LT_None:
            assert(0);
            break;

        case LT_Default:
            out << "default";
            break;

        case LT_Case:
            assert(begin);
            out << "case " << *begin;
            break;

        case LT_CaseRange:
            assert(begin);
            assert(end);
            out << "case " << *begin << " ... " << *end;
            break;

        case LT_Goto:
            assert(name);
            out << *name;
            break;
    }

    out << ":\n";
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Label::findExpr( fnExprCallback cb )
{
    switch (type)
    {
        default:
            break;

        case LT_CaseRange:
            end->findExpr(cb);
        case LT_Case:
            begin->findExpr(cb);
            break;
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement::Statement(StatementType stemntType, const Location& l)
  : location(l)
{
    type  = stemntType;
    next = NULL;

// benny added:
    equalTo = NULL;
    ALLOC_UNIQ_ID();
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement::~Statement()
{
    LabelVector::iterator    j;

    for (j=labels.begin(); j != labels.end(); j++)
    {
        delete *j;
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Statement::addLabel( Label *lbl )
{
    labels.push_back(lbl);

    // Hook the label's symtable entry back to this statement.
    if (lbl->type == LT_Goto)
    {
        if (lbl->name->entry != NULL)
            lbl->name->entry->u2LabelPosition = this;
    }
}

void
Statement::addHeadLabel( Label *lbl )
{
    labels.insert(labels.begin(),lbl);

    // Hook the label's symtable entry back to this statement.
    if (lbl->type == LT_Goto)
    {
        if (lbl->name->entry != NULL)
	{
            lbl->name->entry->u2LabelPosition = this;
            lbl->name->entry->uLabelDef = lbl;
        }
    }
}
// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o

void Statement::removeAllLabels(){
	labels = LabelVector();
}


void Statement::insertBeforeTransUnit(Statement* statementToInsert, TransUnit* enclosingBlock)
{
	Statement* prev = NULL;
	for (Statement *statement = enclosingBlock->head; statement; prev = statement, statement = statement->next)
	{
		if (statement == this){
			statementToInsert -> next = this;
			if (prev == NULL){
				enclosingBlock -> head = statementToInsert;
			}
			else{
				prev -> next = statementToInsert;
			}
			return;
		}

	}
	return;
}

void Statement::insertBeforeInner(Statement* statementToInsert, Block* enclosingBlock)
{
	Statement* prev = NULL;
	for (Statement *statement = enclosingBlock->head; statement; prev = statement, statement = statement->next)
	{
		if (statement == this){
			statementToInsert -> next = this;
			if (prev == NULL){
				enclosingBlock -> head = statementToInsert;
			}
			else{
				prev -> next = statementToInsert;
			}
			return;
		}

		if (statement->statementContainsBlock()){
			std::vector<Block*>* b = statement->getBlockFromStatement();
			for (unsigned int i = 0 ; i < b->size() ; i++){
				Block* currentBlock = b->at(i);
				if (currentBlock->statementIsInBlock(this)){
					insertBeforeInner(statementToInsert, currentBlock);
					return;
				}
			}
		}
	}
	return;
}

void Statement::insertBefore(Statement* statementToInsert, Block* enclosingBlock){
	insertBeforeInner(statementToInsert, enclosingBlock);
}

bool Statement::statementContainsBlock(){
	StatementType t = this -> type;
	return t == ST_Block || t == ST_IfStemnt || t == ST_SwitchStemnt || t == ST_ForStemnt || t == ST_WhileStemnt || t == ST_DoWhileStemnt;
}


std::vector<Block*>* Statement::getBlockFromStatement(){
	std::vector<Block*>* resultBlocks = new std::vector<Block*>();
	Block* block = NULL;
	switch(this -> type)
	{
	case ST_Block:
		resultBlocks -> push_back((Block*)this);
		return resultBlocks;
		break;
	case ST_IfStemnt: {
		IfStemnt* ifStemnt = (IfStemnt*) this;
		Block* thenBlock = ifStemnt->thenBlk->encloseInBlockIfNeeded();
		ifStemnt->thenBlk = thenBlock;
		resultBlocks -> push_back(thenBlock);
		if (ifStemnt -> elseBlk != NULL){
			Block* elseBlock = ifStemnt->elseBlk->encloseInBlockIfNeeded();
			ifStemnt->elseBlk = elseBlock;
			resultBlocks -> push_back(elseBlock);
		}
		return resultBlocks;
		break;
					  }
	case ST_SwitchStemnt:
		block = ((SwitchStemnt*) this)->block->encloseInBlockIfNeeded();
		((SwitchStemnt*) this)->block = block;
		resultBlocks -> push_back(block);
		return resultBlocks;
		break;
	case ST_ForStemnt:
		block = ((ForStemnt*) this)->block->encloseInBlockIfNeeded();
		((ForStemnt*) this)->block = block;
		resultBlocks -> push_back(block);
		return resultBlocks;
		break;
	case ST_WhileStemnt:
		block = ((WhileStemnt*) this)->block->encloseInBlockIfNeeded();
		((WhileStemnt*) this)->block = block;
		resultBlocks -> push_back(block);
		return resultBlocks;
		break;
	case ST_DoWhileStemnt:
		block = ((DoWhileStemnt*) this)->block->encloseInBlockIfNeeded();
		((DoWhileStemnt*) this)->block = block;
		resultBlocks -> push_back(block);
		return resultBlocks;
		break;
	default :
		return NULL;
	}
}

Block* Statement::encloseInBlockIfNeeded(){
	if (type == ST_Block) return (Block*) this;

	Block* enclosingBlock = new Block(location);
	enclosingBlock->head = this;

	return enclosingBlock;
}

Block* Statement::getEnclosingBlock(Block* enclosingBlock){
	for (Statement *statement = enclosingBlock->head; statement; statement = statement->next)
	{
		if (statement == this){
			return enclosingBlock;
		}
	}

	for (Statement *statement = enclosingBlock->head; statement; statement = statement->next)
	{
		if (statement->statementContainsBlock()){
			std::vector<Block*>* b = statement->getBlockFromStatement();
			for (unsigned int i = 0 ; i < b->size() ; i++){
				Block* enclosedBlock = getEnclosingBlock(b->at(i));
				if (enclosedBlock != NULL){
					return enclosedBlock;
				}
			}
		}
	}
	return NULL;
}

Statement* Statement::getEnclosingStatement(Block* enclosingBlock){
	for (Statement *statement = enclosingBlock->head; statement; statement = statement->next)
	{
		if (statement == this){
			return enclosingBlock;
		}
	}

	for (Statement *statement = enclosingBlock->head; statement; statement = statement->next)
	{
		if (statement->statementContainsBlock()){
			std::vector<Block*>* b = statement->getBlockFromStatement();
			for (unsigned int i = 0 ; i < b->size() ; i++){
				Statement* enclosedBlock = getEnclosingStatement(b->at(i));

				if (enclosedBlock != NULL){
					if (enclosedBlock -> type == ST_Block){
						return statement;
					}
					return enclosedBlock;
				}
			}
		}
	}
	return NULL;
}

void Statement::replaceWith(Statement* newStatement, Block* enclosingBlock){
	insertBefore(newStatement, enclosingBlock);
	newStatement -> next = next;
}

void Statement::replaceWithTransUnit(Statement* newStatement, TransUnit* enclosingBlock){
	insertBeforeTransUnit(newStatement, enclosingBlock);
	newStatement -> next = next;
}

bool Statement::isStatementContainCaseLabel(){
	return labels.size() == 1 && labels.at(0)->type == LT_Case;
}
// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
Statement::dup0() const
{
    Statement *ret = new Statement(type, location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Statement::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* Statement:" ;
        location.printLocation(out) ;
        out << " */";
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    switch (type)
    {
      default:
        out << __PRETTY_FUNCTION__ << std::endl;
        out << nameOfStatementType(type) << std::endl;
        break;

      case ST_NullStemnt:          // The null statement.
        out << ";";
        break;

      case ST_ContinueStemnt:
        out << "continue";
        break;

      case ST_BreakStemnt:
        out << "break";
        break;
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Statement::findExpr( fnExprCallback cb )
{
    LabelVector::iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->findExpr(cb);
}




// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
FileLineStemnt::FileLineStemnt(const std::string& incl, int lino, const Location& l):
  Statement( ST_FileLineStemnt, l ), filename(incl), linenumber(lino)
{
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
FileLineStemnt::~FileLineStemnt()
{
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
FileLineStemnt::dup0() const
{
    FileLineStemnt *ret = new FileLineStemnt(filename, linenumber, location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
FileLineStemnt::print(std::ostream& out, int level) const
{
#ifdef PRINT_LOCATION
  out << "$<FileLineStemnt:" ;
  location.printLocation(out) ;
  out << ">$";
#endif

    if (linenumber > 0)
        out << "#line " << linenumber;
    else
        out << "#file";
      
    out << " \"" << filename << "\"" << std::endl;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
InclStemnt::InclStemnt(const std::string& incl, const Location& l):
  Statement( ST_InclStemnt, l )
{
static const char  *NrmPath[] = { "./", NULL };

    int    j;

    isStandard = false;
    filename = incl;

    for (j=0; StdPath[j]; j++)
    {
        if (strncmp(filename.c_str(),StdPath[j],strlen(StdPath[j])) == 0)
        {
            isStandard = true;
            filename = &(filename.c_str()[strlen(StdPath[j])]);
        }
    }

    for (j=0; NrmPath[j]; j++)
    {
        if (strncmp(filename.c_str(),NrmPath[j],strlen(NrmPath[j])) == 0)
        {
            filename = &(filename.c_str()[strlen(NrmPath[j])]);
        }
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
InclStemnt::~InclStemnt()
{
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
InclStemnt::dup0() const
{
    InclStemnt *ret = new InclStemnt(filename, location);
    ret->isStandard = isStandard;
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
InclStemnt::print(std::ostream& out, int level) const
{
#ifdef PRINT_LOCATION
  out << "$<InclStemnt:" ;
  location.printLocation(out) ;
  out << ">$";
#endif

    out << "#include " << (isStandard ? '<' : '"');
    out << filename << (isStandard ? '>' : '"') << std::endl;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
EndInclStemnt::EndInclStemnt(const Location& l)
           : Statement( ST_EndInclStemnt, l )
{
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
EndInclStemnt::~EndInclStemnt()
{
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
EndInclStemnt::dup0() const
{
    EndInclStemnt *ret = new EndInclStemnt(location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
EndInclStemnt::print(std::ostream& out, int level) const
{
#ifdef PRINT_LOCATION
  out << "$<EndInclStemnt:" ;
  location.printLocation(out) ;
  out << ">$";
#endif
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
ExpressionStemnt::ExpressionStemnt( Expression *expr, const Location& l)
                 : Statement( ST_ExpressionStemnt, l )
{
    expression = expr;
}

ExpressionStemnt::ExpressionStemnt( std::string varNameToBeAssigned, SymEntry* matchingSymEntry, int assignmentConst, const Location& l)
	: Statement( ST_ExpressionStemnt, l )
{
	Variable* leftExp = new Variable(varNameToBeAssigned, l, matchingSymEntry);
	IntConstant* rightExp = new IntConstant(assignmentConst, false, l);
	AssignExpr* exp = new AssignExpr(AO_Equal, leftExp, rightExp, l);
	
	expression = exp;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
ExpressionStemnt::~ExpressionStemnt()
{
    delete expression;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
ExpressionStemnt::dup0() const
{
    ExpressionStemnt *ret = new ExpressionStemnt(expression->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
ExpressionStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* ExpressionStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    assert(expression);
    out << *expression;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
ExpressionStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);
    expression->findExpr(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
IfStemnt::IfStemnt( Expression *_cond,
                    Statement *_thenBlk, const Location& l,
                    Statement *_elseBlk /* =NULL */)
         : Statement( ST_IfStemnt, l )
{
    cond = _cond;
    thenBlk = _thenBlk;
    elseBlk = _elseBlk;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
IfStemnt::~IfStemnt()
{
    delete cond;
    delete thenBlk;
    delete elseBlk;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
IfStemnt::dup0() const
{
    IfStemnt *ret = new IfStemnt(cond->dup(),thenBlk->dup(),location,elseBlk->dup());
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
IfStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* IfStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "if (" << *cond << ")\n";
    printBlock(out,level,thenBlk);

    if (elseBlk)
    {
        out << std::endl;
        indent(out,level);
        out << "else\n";
        printBlock(out,level,elseBlk);
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
IfStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    cond->findExpr(cb);

    thenBlk->findExpr(cb);

    if (elseBlk)
        elseBlk->findExpr(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
IfStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    thenBlk->findStemnt(cb);

    if (elseBlk)
        elseBlk->findStemnt(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
SwitchStemnt::SwitchStemnt( Expression *_cond, Statement *_block,
			    const Location& l )
             : Statement( ST_SwitchStemnt, l )
{
    cond = _cond;
    block = _block;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
SwitchStemnt::~SwitchStemnt()
{
    delete cond;
    delete block;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
SwitchStemnt::dup0() const
{
    SwitchStemnt *ret = new SwitchStemnt(cond->dup(),block->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
SwitchStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* SwitchStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "switch (" << *cond << ")\n";

    printBlock(out,level,block);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
SwitchStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);
    cond->findExpr(cb);
    block->findExpr(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
SwitchStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    block->findStemnt(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o

Statement* SwitchStemnt::getFatherCaseStatementOf(Statement* statementToFind){
	Statement* currentCaseStatement = ((Block*) block)->head;
	if (!currentCaseStatement->isStatementContainCaseLabel()){
		throw new std::exception("First statement in a switch block should have a case label on it");
	}

	for (Statement* statement = currentCaseStatement ; statement ; statement = statement->next){
		if (statement->isStatementContainCaseLabel()){
			currentCaseStatement = statement;
		}

		if (statement == statementToFind){
			return currentCaseStatement;
		}

		if (statement->statementContainsBlock()){
			std::vector<Block*>* blocks = statement->getBlockFromStatement();
			for (unsigned int i = 0 ; i < blocks->size() ; i++){
				Block* block = blocks->at(i);
				if (block->statementIsInBlock(statementToFind)){
					return currentCaseStatement;
				}
			}
		}
	}
	return NULL;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
ForStemnt::ForStemnt( Expression *_init, Expression *_cond,
                      Expression *_incr, const Location& l,
		      Statement *_block /* =NULL */)
          : Statement( ST_ForStemnt, l )
{
    init = _init;
    cond = _cond;
    incr = _incr;

    block = _block;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
ForStemnt::~ForStemnt()
{
    delete init;
    delete cond;
    delete incr;

    delete block;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
ForStemnt::dup0() const
{
    ForStemnt *ret = new ForStemnt(init->dup(),cond->dup(),incr->dup(),
                                   location,block->dup());
                                   
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
ForStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* ForStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "for (";

    if (init)
        out << *init;
    out << "; ";

    if (cond)
        out << *cond;
    out << "; ";

    if (incr)
        out << *incr;
    out << ")\n";

    printBlock(out,level,block);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
ForStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    if (init != NULL)
        init->findExpr(cb);

    if (cond != NULL)
        cond->findExpr(cb);

    if (incr != NULL)
        incr->findExpr(cb);

    if (block != NULL)
        block->findExpr(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
ForStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    if (block)
        block->findStemnt(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
WhileStemnt::WhileStemnt( Expression *_cond, Statement *_block,
			  const Location& l)
            : Statement( ST_WhileStemnt, l )
{
    cond = _cond;
    block = _block;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
WhileStemnt::~WhileStemnt()
{
    delete cond;
    delete block;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
WhileStemnt::dup0() const
{
    WhileStemnt *ret = new WhileStemnt(cond->dup(),block->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
WhileStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* WhileStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "while (" << *cond << ")\n";

    printBlock(out,level,block);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
WhileStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    cond->findExpr(cb);

    if (block)
        block->findExpr(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
WhileStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    if (block)
        block->findStemnt(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
DoWhileStemnt::DoWhileStemnt( Expression *_cond, Statement *_block,
			     const Location& l)
              : Statement( ST_DoWhileStemnt, l )
{
    cond = _cond;
    block = _block;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
DoWhileStemnt::~DoWhileStemnt()
{
    delete cond;
    delete block;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
DoWhileStemnt::dup0() const
{
    DoWhileStemnt *ret = new DoWhileStemnt(cond->dup(),block->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
DoWhileStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* DoWhileStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    out << "do ";

    if (!block->isBlock())
        out << std::endl;

    printBlock(out,level,block);

    if (!block->isBlock())
        out << std::endl;

    indent(out,level);
    out << "while (" << *cond << ")";
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
DoWhileStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    cond->findExpr(cb);

    if (block)
        block->findExpr(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
DoWhileStemnt::findStemnt( fnStemntCallback cb )
{
    (cb)(this);

    if (block)
        block->findStemnt(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
GotoStemnt::GotoStemnt( Symbol *_dest, const Location& l)
           : Statement( ST_GotoStemnt, l )
{
    dest = _dest;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
GotoStemnt::~GotoStemnt()
{
    delete dest;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
GotoStemnt::dup0() const
{
    GotoStemnt *ret = new GotoStemnt(dest->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
GotoStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* GotoStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    out << "goto " << *dest;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
ReturnStemnt::ReturnStemnt( Expression *_result, const Location& l)
             : Statement( ST_ReturnStemnt, l )
{
    result = _result;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
ReturnStemnt::~ReturnStemnt()
{
    delete result;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
ReturnStemnt::dup0() const
{
    ReturnStemnt *ret = new ReturnStemnt(result->dup(), location);
    
    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());
        
    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
ReturnStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* ReturnStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    out << "return";

    if (result)
        out << " " << *result;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
ReturnStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    if (result)
        result->findExpr(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
DeclStemnt::DeclStemnt(const Location& l,
		       StatementType stype /* =ST_DeclStemnt */)
      : Statement( stype, l )
{
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
DeclStemnt::~DeclStemnt()
{
    DeclVector::iterator    j;

    for (j=decls.begin(); j != decls.end(); j++)
        delete *j;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
DeclStemnt::addDecl(Decl *decl)
{
    decls.push_back(decl);
}

void
DeclStemnt::addDecls(Decl *decls)
{
    Decl    *decl = decls;

    while (decls != NULL)
    {
        decls = decls->next;
        decl->next = NULL;
        //std::cout << "Decl is: ";
        //decl->print(std::cout,true);
        //std::cout << std::endl;
        addDecl(decl);
        decl = decls;
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
DeclStemnt::dup0() const
{
    DeclStemnt *ret;
    if (type == ST_TypedefStemnt)
        ret = new TypedefStemnt(location);
    else
        ret = new DeclStemnt(location);

    DeclVector::const_iterator    j;
    for (j=decls.begin(); j != decls.end(); j++)
        ret->addDecl((*j)->dup());

    LabelVector::const_iterator    k;
    for (k=labels.begin(); k != labels.end(); k++)
        ret->addLabel((*k)->dup());

    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
DeclStemnt*
DeclStemnt::convertToTypedef()
{
    // Nothing to do?
    if (isTypedef())
        return this;

    TypedefStemnt *ret = new TypedefStemnt(location);

    // Since we are really the same thing,
    // let's just steal the insides.
    LabelVector::iterator    k;
    for (k=labels.begin(); k != labels.end(); k++)
    {
        ret->addLabel(*k);
    }
    labels.clear();

    ret->next    = next;
    next = NULL;

    DeclVector::iterator    j;

    for (j=decls.begin(); j != decls.end(); j++)
    {
        ret->addDecl(*j);
    }

    decls.clear();

    delete this;        // Danger - Will Robinson!

    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
DeclStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* DeclStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    if (!decls.empty())
    {
        DeclVector::const_iterator    j = decls.begin();

        (*j)->print(out,true,level);
        for (j++; j != decls.end(); j++)
        {
            out << ", ";
            (*j)->print(out,false,level);
        }
    }

    out << ";";
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
DeclStemnt::findExpr( fnExprCallback cb )
{
    Statement::findExpr(cb);

    DeclVector::iterator    j;

    for (j = decls.begin(); j != decls.end(); j++)
    {
        (*j)->findExpr(cb);
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
TypedefStemnt::TypedefStemnt(const Location& l)
              : DeclStemnt( l, ST_TypedefStemnt )
{
}

TypedefStemnt::~TypedefStemnt()
{
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
TypedefStemnt::print(std::ostream& out, int level) const
{
    if (Project::gDebug)
    {
        out << "/* TypedefStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);

    out << "typedef ";

    if (!decls.empty())
    {
        DeclVector::const_iterator    j = decls.begin();

        (*j)->print(out,true,level);
        for (j++; j != decls.end(); j++)
        {
            out << ", ";
            (*j)->print(out,false,level);
        }
    }

    out << ";";
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Block::Block(const Location& l)
      : Statement( ST_Block , l )
{
    head = tail = NULL;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Block::~Block()
{
    Statement *stemnt, *prevStemnt = NULL;

    for (stemnt=head; stemnt; stemnt=stemnt->next)
    {
        delete prevStemnt;
        prevStemnt = stemnt;
    }
    delete prevStemnt;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Block::add(Statement *stemnt)
{
    if (stemnt)
    {
        stemnt->next = NULL;
    
        if (tail)
            tail->next = stemnt;
        else
            head = stemnt;
    
        tail = stemnt;
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Block::addStatements(Statement* stemnts)
{
    Statement*    stemnt;

    while (stemnts != NULL)
    {
        stemnt = stemnts;
        stemnts = stemnts->next;

        stemnt->next = NULL;
        add(stemnt);
    }
}

void
Block::addDecls(Decl* decls)
{
    Decl    *decl = decls;

    while (decls != NULL)
    {
        DeclStemnt*   ds = new DeclStemnt(location);

        decls = decls->next;
        decl->next = NULL;

        ds->addDecl(decl);
        add(ds);        

        decl = decls;
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
Block::dup0() const
{
    Block *ret = new Block(location);

    for (Statement *stemnt=head; stemnt; stemnt=stemnt->next)
        ret->add(stemnt->dup());

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());

    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Block::print(std::ostream& out, int level) const
{
    bool       isDecl;
    Statement *stemnt;

    if (Project::gDebug)
    {
        out << "/* BlockStemnt:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        (*j)->print(out,level);

    indent(out,level);
    out << "{\n";

    isDecl = (head != NULL) ? head->isDeclaration() : false;
    for (stemnt=head; stemnt; stemnt=stemnt->next)
    {
        if (isDecl && !stemnt->isDeclaration())
        {
            isDecl = false;
            out << std::endl;
        }

        stemnt->print(out,level+1);

        if (stemnt->needSemicolon())
            out << ";";
        out << std::endl;
    }

    indent(out,level);
    out << "}\n";
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Block::findExpr( fnExprCallback cb )
{
    Statement *stemnt;

    Statement::findExpr(cb);

    for (stemnt=head; stemnt; stemnt=stemnt->next)
    {
        stemnt->findExpr(cb);
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Block::findStemnt( fnStemntCallback cb )
{
    Statement *stemnt;

    (cb)(this);

    for (stemnt=head; stemnt; stemnt=stemnt->next)
    {
        stemnt->findStemnt(cb);
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
Block::insert(Statement *stemnt, Statement *after /* =NULL */)
{
    if (stemnt)
    {
        stemnt->next = NULL;
    
        if (tail)
        {
            if (after)
            {
                stemnt->next = after->next;
                after->next = stemnt;
            }
            else
            {
                stemnt->next = head;
                head = stemnt;
            }

            if (stemnt->next == NULL)
                tail = stemnt;
        }
        else
            head = tail = stemnt;
    }
}
// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
bool Block::statementIsInBlock(Statement* statementToFind){
	for (Statement *statement = this->head; statement; statement = statement->next)
	{
		if (statement == statementToFind)		{
			return true;
		}
		if (statement->statementContainsBlock()){
			std::vector<Block*>* b = statement -> getBlockFromStatement();
			for (unsigned int i = 0 ; i < b->size() ; i++){
				if (b->at(i)->statementIsInBlock(statementToFind)){
					return true;
				}
			}
		}
	}
	return false;
}

int Block::statementCount(){
	int count = 0;

	for (Statement *statement = head; statement; statement = statement->next)
	{
		if (statement->statementContainsBlock()){
			std::vector<Block*>* b = statement->getBlockFromStatement();
			for (unsigned int i = 0 ; i < b->size() ; i++){
				Block* block = b->at(i);
				int innerBlockCount = block->statementCount();
				
				//add two lines for the head of the block (if().. while()..) and
				//for the closing bracket
				count+=innerBlockCount + 1 + 1; 
			}
		}
		else{
			count++;
		}
	}
	return count;
}

bool Block::isStatementSingleInBlock(Statement* statementToFind){
	if (statementToFind == NULL) return false;
	if (head == NULL) return false;
	if (head != statementToFind) return false;
	return head -> next == NULL;
}

void Block::setBlockHead(Statement* newHead){
	if (newHead){
		newHead -> next = head;
		head = newHead;
	}
}

void Block::appendToTail(Statement* newTail){
	Statement* temp = head;

	while(temp -> next != NULL){
		temp = temp -> next;
	}

	temp -> next = newTail;
}

bool Block::removeStatement(Statement* statementToRemove){
	Statement* prev = NULL;
	for (Statement* statement = head ; statement != NULL ; prev = statement, statement = statement -> next){
		if (statement == statementToRemove){
			if (prev == NULL){
				head = statementToRemove->next;
			}
			else{
				prev->next = statementToRemove->next;
			}
			return true;
		}


		if (statement->statementContainsBlock()){
			std::vector<Block*>* b = statement->getBlockFromStatement();
			for (unsigned int i = 0 ; i < b->size() ; i++){
				Block* block = b->at(i);
				if (block->removeStatement(statementToRemove)){
					return true;
				}
			}
		}
	}
	return false;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void Block::inherit(Block *source) {
	// Steal internals of the source block and release the latter.
    if (source == NULL)
    	return;

	if (source->head != NULL) { // There is something to inherit:
		if (head == NULL)
			head = source->head;
		else
			tail->next = source->head;
		tail = source->tail;
	}

 	source->head = source->tail = (Statement*) NULL;
	delete source;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
FunctionDef::FunctionDef(const Location& l)
            : Block(l)
{
    decl = NULL;
}

FunctionDef::~FunctionDef()
{

    delete decl;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Statement*
FunctionDef::dup0() const
{
    FunctionDef *ret = new FunctionDef(location);
    ret->decl = decl->dup();

    for (Statement *stemnt=head; stemnt; stemnt=stemnt->next)
        ret->add(stemnt->dup());

    LabelVector::const_iterator    j;
    for (j=labels.begin(); j != labels.end(); j++)
        ret->addLabel((*j)->dup());

    return ret;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
FunctionDef::print(std::ostream& out, int) const
{
    if (Project::gDebug)
    {
        out << "/* FunctionDef:" ;
        location.printLocation(out) ;
        out << " */" << std::endl;
    }

    decl->print(out,true); 
    out << std::endl;

    Block::print(out,0);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
void
FunctionDef::findExpr( fnExprCallback cb )
{
    decl->findExpr(cb);

    Block::findExpr(cb);
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
Symbol*
FunctionDef::FunctionName() const
{
    return decl->name;
}

bool FunctionDef::isVoid()
{
	return this->decl->form->isVoid();
}


// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
std::ostream&
operator<< (std::ostream& out, const Statement& stemnt)
{
    stemnt.print(out,0);
    return out;
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
#define  SHOW(X)  case X: return #X

const char*
nameOfStatementType( StatementType type )
{
    switch (type)
    {
        default:
            return "Unknown StatementType";

        SHOW(ST_NullStemnt);
        SHOW(ST_DeclStemnt);
        SHOW(ST_ExpressionStemnt);
        SHOW(ST_IfStemnt);
        SHOW(ST_SwitchStemnt);
        SHOW(ST_ForStemnt);
        SHOW(ST_WhileStemnt);
        SHOW(ST_DoWhileStemnt);
        SHOW(ST_ContinueStemnt);
        SHOW(ST_BreakStemnt);
        SHOW(ST_GotoStemnt);
        SHOW(ST_ReturnStemnt);
        SHOW(ST_Block);
        SHOW(ST_InclStemnt);
        SHOW(ST_EndInclStemnt);
    }
}

// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o
const char*
nameOfLabelType( LabelType type )
{
    switch (type)
    {
        default:
            return "Unknown LabelType";

        SHOW(LT_None);        // No label - invalid.
        SHOW(LT_Default);     // default:
        SHOW(LT_Case);        // case <expr>:
        SHOW(LT_Goto);        // A named label (goto destination).
    }
}

#undef SHOW
// o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o+o

