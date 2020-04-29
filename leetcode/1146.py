from collections import defaultdict
import copy

class SnapshotArray:

  def __init__(self, length: int):
    self.arr = defaultdict(int)
    self.snaps = defaultdict(list)
    self.snap_id = 0

  def set(self, index: int, val: int) -> None:
    key = (self.snap_id, index)
    self.arr[key] = val

  def snap(self) -> int:
    self.snap_id += 1
    return self.snap_id - 1

  def get(self, index: int, snap_id: int) -> int:
    # print(self.snaps)
    for sid in range(snap_id, -1, -1):
      key = (sid, index)
      # print("get ", key)
      if key in self.arr:
        return self.arr[key]
    return 0
    # return self.snaps[snap_id][index]



# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)