
#ifndef CGMODULE_PPC_H
#define CGMODULE_PPC_H

#include "cgmodule.h"
#include "cgframe_ppc.h"

struct CGModule_PPC : public CGModule{
	string		seg;
	CGSym*		fp_const;
	bool 		isApple;
	int			linkagearea;
	
	string      reg;
	string      freg;
	string      r[32];
	string		f[32];
	
	
	CGModule_PPC( std::ostream &out );
	
	void		setSeg( string t );
	
	CGFrame*	frame( CGFun *fun );
	void		emitHeader();
	void		emitImport( string t );
	void		emitExport( string t );
	void		emitFrame( CGFrame *f );
	void		emitData( CGDat *d );
	void		emitFooter();
};

#endif

