#ifndef ALGOL_H
#define ALGOL_H

template<typename Iter, typename T>
Iter auFind(Iter beg, Iter end, const T& elem)
{
	while (beg != end and *beg != elem)
	{
		++beg;
	}
	return beg;
}

template<typename Iter, typename P>
Iter auFindIf(Iter beg, Iter end, P pred)
{
	while (beg != end and not pred(*beg))
	{
		++beg;
	}
	return beg;
}
#endif