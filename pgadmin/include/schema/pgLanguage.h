//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
//
// Copyright (C) 2002 - 2012, The pgAdmin Development Team
// This software is released under the PostgreSQL Licence
//
// pgLanguage.h PostgreSQL Language
//
//////////////////////////////////////////////////////////////////////////

#ifndef PGLANGUAGE_H
#define PGLANGUAGE_H

#include "pgDatabase.h"

class pgCollection;
class pgLanguageFactory : public pgDatabaseObjFactory
{
public:
	pgLanguageFactory();
	virtual dlgProperty *CreateDialog(frmMain *frame, pgObject *node, pgObject *parent);
	virtual pgObject *CreateObjects(pgCollection *obj, ctlTree *browser, const wxString &restr = wxEmptyString);
	virtual pgCollection *CreateCollection(pgObject *obj);
};
extern pgLanguageFactory languageFactory;

class pgLanguage : public pgDatabaseObject
{
public:
	pgLanguage(const wxString &newName = wxT(""));

	wxString GetTranslatedMessage(int kindOfMessage) const;
	void ShowTreeDetail(ctlTree *browser, frmMain *form = 0, ctlListView *properties = 0, ctlSQLBox *sqlPane = 0);
	bool CanDropCascaded()
	{
		return true;
	}

	wxString GetHandlerProc() const
	{
		return handlerProc;
	}
	void iSetHandlerProc(const wxString &s)
	{
		handlerProc = s;
	}
	wxString GetValidatorProc() const
	{
		return validatorProc;
	}
	void iSetValidatorProc(const wxString &s)
	{
		validatorProc = s;
	}
	bool GetTrusted() const
	{
		return trusted;
	}
	void iSetTrusted(const bool b)
	{
		trusted = b;
	}

	bool DropObject(wxFrame *frame, ctlTree *browser, bool cascaded);
	wxString GetSql(ctlTree *browser);
	pgObject *Refresh(ctlTree *browser, const wxTreeItemId item);

	bool HasStats()
	{
		return false;
	}
	bool HasDepends()
	{
		return true;
	}
	bool HasReferences()
	{
		return true;
	}

private:
	wxString handlerProc, validatorProc;
	bool trusted;
};

class pgLanguageCollection : public pgDatabaseObjCollection
{
public:
	pgLanguageCollection(pgaFactory *factory, pgDatabase *db);
	wxString GetTranslatedMessage(int kindOfMessage) const;
};

#endif
