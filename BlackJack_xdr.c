/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "BlackJack.h"

bool_t
xdr_Hand (XDR *xdrs, Hand *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (2 +  50  + 50 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->player_cards, 50,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->player_count))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->dealer_cards, 50,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->dealer_count))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->player_cards;
					i < 50; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->player_count);
			{
				register int *genp;

				for (i = 0, genp = objp->dealer_cards;
					i < 50; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->dealer_count);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (2 +  50  + 50 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->player_cards, 50,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->player_count))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->dealer_cards, 50,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->dealer_count))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->player_cards;
					i < 50; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->player_count = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->dealer_cards;
					i < 50; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->dealer_count = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->player_cards, 50,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->player_count))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->dealer_cards, 50,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->dealer_count))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_Result (XDR *xdrs, Result *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->player))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->dealer))
		 return FALSE;
	return TRUE;
}
