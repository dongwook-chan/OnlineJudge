right_item_with_colors = ["white Barabashka", "blue book", "red chair", "gray mouse", "green bottle"]

for _ in range(5):
    sentence = input()
    sentence = sentence.replace("'", " ").replace(",", " ").replace("-", " ").replace(".", " ")
    # sentence_lower = sentence.lower()

    visited_colors = {"white": None, "blue": None, "red": None, "gray": None, "green": None}
    visited_items = {"barabashka": None, "book": None, "chair": None, "mouse": None, "bottle": None}

    for word_original in sentence.split():
        word = word_original.lower()
        if word in visited_colors:
            visited_colors[word] = word_original
        elif word in visited_items:
            visited_items[word] = word_original

    for color, item in zip(visited_colors.values(), visited_items.values()):
        if color is not None and item is not None:
            print(color, item)
            break
    else:
        for color, item in zip(visited_colors.keys(), visited_items.keys()):
            if visited_colors[color] is not None or visited_items[item] is not None:
                continue
            if item == "barabashka":
                item = "Barabashka"
            print(color, item)
            break
