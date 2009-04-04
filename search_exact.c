/*
 * This is a fragment, included from multiple places in ebwt_search.cpp.
 * It implements the logic of the exact-search routine.  It is
 * implemented as a code fragment so that it can be reused in both
 * paired and unpaired alignment.
 */
{
	uint32_t plen = length(patsrc->bufa().patFw);
	// Process forward-oriented read
	bt.setOffs(0, 0, plen, plen, plen, plen);
	bt.setQuery(patsrc->bufa());
	bool hit = bt.backtrack();
	// If the forward direction matched exactly, ignore the
	// reverse complement
	if(hit) {
		continue;
	}
	if(!revcomp) continue;
	// Process reverse-complement read
	params.setFw(false);
	bt.setQuery(patsrc->bufa());
	bt.backtrack();
	params.setFw(true);
}
