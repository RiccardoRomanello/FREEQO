from Driver import Driver
from InputReader import InputReader
import numpy as np

file_name = "input.txt"

print("Reading input from {}...".format(file_name))
d = InputReader(file_name).read_input()
print("Input read!")

print("Initial graph:")
d.graph.pretty_print()

print("Computing unitary from graph...")
hat_M = d.Unitarize()
print("Done!")
print("Unitarized matrix:")
print(hat_M)