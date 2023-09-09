def move_tower(n, start_peg, end_peg):
    """Perform moves that transfer an ordered tower of N>0 disks in the Towers of Hanoi puzzle from peg START_PEG to peg END_PEG,
    where 1 <= START_PEG, END_PEG <= 3, and START_PEG != END_PEG. Assumes the disks to be moved are all smaller than those on the 
    other pegs."""
    if n == 1:
        move_disk(start_peg, end_peg)
    else:
        # three pegs, are some permutation of 1, 2, 3
        # get the number of the spare peg   
        spare_peg = 6 - start_peg - end_peg
        
        # move the remaining n - 1 disks from start_peg to spare_peg
        move_tower(n - 1, start_peg, spare_peg)

        # move the remaining one disk from start_peg to end_peg
        move_disk(start_peg, end_peg)

        move_tower(n - 1, spare_peg, end_peg)


def move_disk(start_peg, end_peg):
    print("moving one disk from", start_peg, "to", end_peg)