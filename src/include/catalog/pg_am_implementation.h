/*-------------------------------------------------------------------------
 *
 * pg_am_impl.h
 *	  definition of the "access method" system catalog (pg_am)
 *
 *
 * Portions Copyright (c) 1996-2023, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/pg_am_impl.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_AM_IMPL_H
#define PG_AM_IMPL_H

#include "catalog/genbki.h"
#include "catalog/pg_am_impl_d.h"

/* ----------------
 *		pg_am_impl definition.  cpp turns this into
 *		typedef struct FormData_pg_am
 * ----------------
 */
CATALOG(pg_am,3001,AccessMethodImplementationId)
{
	Oid			imploid;				/* implementation oid */
	Oid			amoid;					/* index/AM oid */

	/* access method implementation name e.g. tableam name for particular index implementation */
	NameData	implname;				/* implementation name */

	/* handler function */
	regproc		handler BKI_LOOKUP(pg_proc);

} FormData_pg_am_impl;

/* ----------------
 *		Form_pg_am corresponds to a pointer to a tuple with
 *		the format of pg_am relation.
 * ----------------
 */
typedef FormData_pg_am_impl *Form_pg_am_impl;

DECLARE_UNIQUE_INDEX(pg_am_impl_implname_index, 3051, AmImplImplnameIndexId, on pg_am_impl using btree(implname name_ops));
DECLARE_UNIQUE_INDEX_PKEY(pg_am_impl_imploid_index, 3052, AmImplImploidIndexId, on pg_am_impl using btree(imploid oid_ops));
DECLARE_INDEX(pg_am_impl_amoid_index, 3053, AmImplAmoidIndexId, on pg_am_impl using btree(amoid oid_ops));

#endif							/* PG_AM_H */
