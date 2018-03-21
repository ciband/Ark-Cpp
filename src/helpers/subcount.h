

#ifndef SUBCOUNT_H
#define SUBCOUNT_H

/*************************************************
* subCount(const char *str, const char* substr)
*
*		Returns number of times a substring(subStr)
*   appears in a provided string(str)
**************************************************/
int subCount(const char *str, const char* subStr)
{
  if (strlen(subStr) == 0) return -1;
  int count = 0;
  for (char* s = (char*)str; (s = strstr(s, subStr)); s++)
    ++count;
  return count;
};
/*************************************************/

#endif
