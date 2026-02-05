from collections import Counter

def leastInterval(tasks, n):
    
    taskcount = Counter(tasks)
    
    
    freq = max(taskcount.values())
    
    
    count = list(taskcount.values()).count(freq)
    

    partcount = freq - 1
    partlength = n - (count - 1)
    empty = partcount * partlength
    availabletasks = len(tasks) - (freq * count)
    time = max(0, empty - availabletasks)
    
    return len(tasks) + time


# Example
tasks = ["A", "A", "A", "B", "B", "B"]
n = 2

print("Minimum Time Required:", leastInterval(tasks, n))
