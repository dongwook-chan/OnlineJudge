right_item_with_colors = ["white Barabashka", "blue book", "red chair", "gray mouse", "green bottle"]

for _ in range(5):
    sentence = input()
    sentence = sentence.replace("'", "").replace(",", "").replace("-", "").replace(".", "")
    # sentence_lower = sentence.lower()

    visited_colors = {"white": False, "blue": False, "red": False, "gray": False, "green": False}
    visited_items = {"Barabashka": False, "book": False, "chair": False, "mouse": False, "bottle": False}
    for right_item_with_color in right_item_with_colors:
        if right_item_with_color in sentence:
            print(right_item_with_color)
            break
    else:
        for word in sentence.split():
            if word != "Barabashka":
                word = word.lower()
            if word in visited_colors:
                visited_colors[word] = True
            elif word in visited_items:
                visited_items[word] = True

        for color, item in zip(visited_colors.keys(), visited_items.keys()):
            if visited_colors[color] or visited_items[item]:
                continue
            print(color, item)
            break
