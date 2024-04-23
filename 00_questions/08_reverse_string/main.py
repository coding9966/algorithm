def reverse(s):
    s_list = list(s)
    s_list[0], s_list[-1] = s_list[-1], s_list[0]
    return''.join(s_list)

def main():
    s = "abcd"
    print("Original string:", s)
    
    reversed_str = reverse(s)
    
    print("Reversed string:", reversed_str)

if __name__ == "__main__":
    main()
