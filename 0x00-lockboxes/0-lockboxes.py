#!/usr/bin/python3


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened """

    keys = []
    for i in range(len(boxes)):
        for j in range(len(boxes[i])):
            if i < boxes[i][j] < len(boxes):
                keys.append(boxes[i][j])
        if len(boxes[i]) == 0 and i == len(boxes) - 1:
            keys.append(0)
    return True if len(keys) == len(boxes) else False
