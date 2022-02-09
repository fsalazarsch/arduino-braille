#include <stdlib.h>
#include <stddef.h>


#if (__STDC_VERSION__ >= 199901L)
#include <stdint.h>
#endif

/*
Created by: Laird Shaw (Thank you :D)
Licence:	Public domain
Site: https://creativeandcritical.net/str-replace-c#repl_wcs
*/

wchar_t *repl_wcs(wchar_t *str, wchar_t *from, wchar_t *to) {

	/* Adjust each of the below values to suit your needs. */

	/* Increment positions cache size initially by this number. */
	size_t cache_sz_inc = 16;
	/* Thereafter, each time capacity needs to be increased,
	 * multiply the increment by this factor. */
	const size_t cache_sz_inc_factor = 3;
	/* But never increment capacity by more than this number. */
	const size_t cache_sz_inc_max = 1048576;

	wchar_t *pret, *ret = NULL;
	const wchar_t *pstr2, *pstr = str;
	size_t i, count = 0;
	#if (__STDC_VERSION__ >= 199901L)
	uintptr_t *pos_cache_tmp, *pos_cache = NULL;
	#else
	ptrdiff_t *pos_cache_tmp, *pos_cache = NULL;
	#endif
	size_t cache_sz = 0;
	size_t cpylen, orglen, retlen, tolen, fromlen = wcslen(from);

	/* Find all matches and cache their positions. */
	while ((pstr2 = wcsstr(pstr, from)) != NULL) {
		count++;

		/* Increase the cache size when necessary. */
		if (cache_sz < count) {
			cache_sz += cache_sz_inc;
			pos_cache_tmp = realloc(pos_cache, sizeof(*pos_cache) * cache_sz);
			if (pos_cache_tmp == NULL) {
				goto end_repl_wcs;
			} else pos_cache = pos_cache_tmp;
			cache_sz_inc *= cache_sz_inc_factor;
			if (cache_sz_inc > cache_sz_inc_max) {
				cache_sz_inc = cache_sz_inc_max;
			}
		}

		pos_cache[count-1] = pstr2 - str;
		pstr = pstr2 + fromlen;
	}

	orglen = pstr - str + wcslen(pstr);

	/* Allocate memory for the post-replacement string. */
	if (count > 0) {
		tolen = wcslen(to);
		retlen = orglen + (tolen - fromlen) * count;
	} else	retlen = orglen;
	ret = malloc((retlen + 1) * sizeof(wchar_t));
	if (ret == NULL) {
		goto end_repl_wcs;
	}

	if (count == 0) {
		/* If no matches, then just duplicate the string. */
		wcscpy(ret, str);
	} else {
		/* Otherwise, duplicate the string whilst performing
		 * the replacements using the position cache. */
		pret = ret;
		wmemcpy(pret, str, pos_cache[0]);
		pret += pos_cache[0];
		for (i = 0; i < count; i++) {
			wmemcpy(pret, to, tolen);
			pret += tolen;
			pstr = str + pos_cache[i] + fromlen;
			cpylen = (i == count-1 ? orglen : pos_cache[i+1]) - pos_cache[i] - fromlen;
			wmemcpy(pret, pstr, cpylen);
			pret += cpylen;
		}
		ret[retlen] = L'\0';
	}

	end_repl_wcs:
	/* Free the cache and return the post-replacement string,
	 * which will be NULL in the event of an error. */
	free(pos_cache);
	return ret;
	}


wchar_t *itoa(int val, int base, int flag){
	

	if (val == 0){
		if (flag ==1){
			return L"#0@";
		}
		else{
			return L"0";
		}
	}

	static wchar_t buf[32] = {0};
	static wchar_t buf0[32] = {0};
	int i = 30;
	

	for(; val && i ; --i, val /= base){
		buf[i] = "0123456789abcdef"[val % base];
		buf0[i] = "0123456789abcdef"[val % base];
		
	}

	if(flag == 0){
		//buf[31] = 0;
		return &buf0[i+1];
	}

	if (flag == 1){
		buf[i] = '#';
		buf[31] = '@';
		return &buf[i];
	}
	else
		return L"0";
	}
wchar_t *reverse_wst( wchar_t *str){

	int length = wcslen(str);
	wchar_t *wchr = NULL;
	wchr = (wchar_t *)malloc((length + 1) * sizeof(wchar_t));
	int last_pos = length-1;

	for(int i = 0; i < length; i++)
	    wchr[last_pos - i] = str[i];
	return wchr;
	}



