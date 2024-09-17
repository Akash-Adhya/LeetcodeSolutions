
class Solution:

    def uncommonFromSentences(self, s1: str, s2: str) -> list[str]:
        answer = []

        s1List = s1.split(" ")
        s2List = s2.split(" ")

        for elem in s1List:
            if s1List.count(elem) == 1 :
                if elem not in s2List:
                    answer.append(elem)

        for elem in s2List:
            if s2List.count(elem) == 1 :
                if elem not in s1List:
                    answer.append(elem)

        return answer

obj= Solution()
ans = obj.uncommonFromSentences("This is an apple", "This is a banana")
print(ans)
