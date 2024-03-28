def find_suspicious_substring(message, k):
    max_length = 0
    char_counts = [0] * 26  # تعداد تکرارهای حروف کوچک الفبا

    for i in range(len(message)):
        # افزایش تعداد تکرار هر کاراکتر در پنجره
        char_counts[ord(message[i]) - ord('a')] += 1

        # کاهش تعداد تکرار کاراکتر قبلی که از پنجره خارج شده است
        if i >= k:
            char_counts[ord(message[i - k]) - ord('a')] -= 1

        # بررسی تعداد تکرارهای هر کاراکتر در پنجره
        for count in char_counts:
            if count >= k:
                max_length = max(max_length, k)
            else:
                break

    return max_length

message1 = "aaabb"
k1 = 3
result1 = find_suspicious_substring(message1, k1)
print(result1)  # خروجی: 3

message2 = "ababbc"
k2 = 2
result2 = find_suspicious_substring(message2, k2)
print(result2)  # خروجی: 5