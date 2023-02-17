a = input()
a = a.lower()

ans = [0]*26

for i in a:
    ans[ord(i)-ord('a')] += 1

# if max in ans is duplicated, print ?
if ans.count(max(ans)) > 1:
    print('?')
else:
    print(chr(ans.index(max(ans))+ord('a')).upper())
