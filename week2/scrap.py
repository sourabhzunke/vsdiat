import re

class Instruction:
    def __init__(self, mnemonic, cycle_count):
        self.mnemonic = mnemonic
        self.cycle_count = cycle_count

def parse_file(filename):
    instruction_cycle_counts = {
        # ... (same as previous response)
        "add": Instruction("add", 1),
        "sub": Instruction("sub", 1),
        "subw": Instruction("subw", 1),
        "sll": Instruction("sll", 1),
        "srl": Instruction("srl", 1),
        "sra": Instruction("sra", 1),
        "xor": Instruction("xor", 1),
        "or": Instruction("or", 1),
        "not": Instruction("not", 1),
        "and": Instruction("and", 1),
        "slt": Instruction("slt", 1),
        "sltu": Instruction("sltu", 1),
        "beq":Instruction("beq", 2),
        "bne":Instruction("bne", 2),
        "blt":Instruction("blt", 2),
        "bge":Instruction("bge", 2),
        "bltu":Instruction("bltu", 2),
        "bgeu":Instruction("bgeu", 2),
        "addi":Instruction("addi", 1),
        "addw":Instruction("addi", 1),
        "slti":Instruction("slti", 1),
        "srliw":Instruction("srliw", 1),
        "sltiu":Instruction("sltiu", 1),
        "xori": Instruction("xori", 1),
        "ori": Instruction("ori", 1),
        "andi": Instruction("andi", 1),
        "slli": Instruction("slli", 1),
        "srli": Instruction("srli", 1),
        "srai": Instruction("srai", 1),
        "lb": Instruction("lb", 4),  # Assuming a memory access of 3 cycles
        "lh": Instruction("lh", 4),
        "lw": Instruction("lw", 4),
        "ld": Instruction("lw", 4),
        "lbu": Instruction("lbu", 3),
        "lhu": Instruction("lhu", 3),
        "sb": Instruction("sb", 3),
        "sh": Instruction("sh", 3),
        "sw": Instruction("sw", 3),
        "sd": Instruction("sd", 3),
        "li": Instruction("li", 2),
        "mv": Instruction("mv", 1),
        "lui": Instruction("lui", 1),
        "jal": Instruction("jal", 2),
        "jr": Instruction("jal", 2),
        "j": Instruction("jal", 1),
        "auipc":Instruction("auipc",1),
        "beqz":Instruction("beqz",2),
        "bnez":Instruction("bnez",2),
        "beqz":Instruction("beqz",2),
        "jalr":Instruction("jalr",2),
        "sllw":Instruction("sllw",1),
        "addiw":Instruction("addiw",2),
        "bltz":Instruction("bltz",2),
        "negw":Instruction("negw",1)
}
    total_cycles = 0
    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()  # Remove leading/trailing whitespace
            match = re.search(r"(\w+)\s+(\w+)\s+(\w+)", line)
            if match:
                opcode = match.group(2)  # Extract the third word as the opcode
                print(opcode)
                if opcode in instruction_cycle_counts:
                    cycle_count = instruction_cycle_counts[opcode].cycle_count
                    total_cycles += cycle_count
                    print(f"Opcode: {opcode}, Cycle Count: {cycle_count}, Total Cycles: {total_cycles}")

    return total_cycles

if __name__ == "__main__":
    total_cycles = parse_file("mat.asm.txt")
    print("Total cycles:", total_cycles)

