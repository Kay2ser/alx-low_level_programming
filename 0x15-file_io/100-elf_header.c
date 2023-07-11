#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stddef.h>

/**
 * print_error - Print error message to stderr and exit with status code 98.
 * @message: The error message to display.
 */
void print_error(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

/**
 * print_elf_header - Print the ELF header information.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_header(const Elf64_Ehdr *header)
{
    int i; /* Declare variable outside the loop in C90 */

    printf("ELF Header:\n");

    /* Print Magic */
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    /* Print Class */
    printf("  Class:                             %s\n",
           header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid");

    /* Print Data */
    printf("  Data:                              %s\n",
           header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid");

    /* Print Version */
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    /* Print OS/ABI */
    printf("  OS/ABI:                            %s\n",
           header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
           header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX" :
           header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "NetBSD" :
           header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "Linux" : "Unknown");

    /* Print ABI Version */
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    /* Print Type */
    printf("  Type:                              %s\n",
           header->e_type == ET_NONE ? "None (No file type)" :
           header->e_type == ET_REL ? "Relocatable file" :
           header->e_type == ET_EXEC ? "EXEC (Executable file)" :
           header->e_type == ET_DYN ? "Shared object file" :
           header->e_type == ET_CORE ? "Core file" : "Unknown");

    /* Print Entry point address */
    printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: Array of string arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
    const char *filename;
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
    }

    filename = argv[1];
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        print_error("Failed to open the file");
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        close(fd);
        print_error("Failed to read ELF header");
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        close(fd);
        print_error("Not an ELF file");
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}

