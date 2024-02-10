# 트리에서 다음 노드 방문하는 함

class Folder:
    def __init__(self, toggle: bool, subfolder: tuple[int]):
        self.toggle: bool = toggle
        self.subfolder: tuple[int] = subfolder

folders: list[Folder] = [None]

def traverse(folder_no:int) -> list[int]:
    folder = folders[folder_no]

    traverse_order = [folder_no]
    if folder.toggle:
        for subfolder_no in folder.subfolder:
            traverse_order.extend(traverse(subfolder_no))
    return traverse_order

def next_folder_no_to_traverse(folder_no: int):
    traverse_order = traverse(1, [])
    return traverse_order[1:]

N, Q = map(int, input().split())
_, *subfolder = map(int, input().split())
folders.append(Folder(True, tuple(subfolder)))
for _ in range(N - 1):
    _, *subfolder = map(int, input().split())
    folders.append(Folder(False, tuple(subfolder)))

traverse_order = traverse(1)[1:]
cur_folder_no = traverse_order[0]
for _ in range(Q):
    cur_folder = folders[cur_folder_no]

    cmd = input()
    if cmd == 'toggle':
        cur_folder.toggle = not cur_folder.toggle
    else:
        cmd, distance = cmd.split()
        distance = int(distance)

        traverse_order = traverse(1)[1:]
        cur_folder_index = traverse_order.index(cur_folder_no)

        if distance < 0 and cur_folder_index + distance < 0:
            next_folder_index = 0
        elif distance > 0 and cur_folder_index + distance >= len(traverse_order):
            next_folder_index = len(traverse_order) - 1
        else:
            next_folder_index = cur_folder_index + distance

        cur_folder_no = traverse_order[next_folder_index]

        print(cur_folder_no)