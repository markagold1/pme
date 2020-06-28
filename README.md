Lightweight file encryption and decryption utility

# What is it?
PME is a lightweight file encryption and decryption command line utility. It is written in C++ using only the Standard Library and no external depencies. PME has been build and tested on Windows 10 and Ubuntu on x86 architecture.

In this repository you'll find:
* C++ source code
* Simple build script
* Test example
# Usage
* **pme infile outfile password**
# Description
* **infile** input file to be encrypted or decrypted
* **outfile** output file
* **password** password (key) to encrypt or decrypt with
# Example
* Encrypt a plain unecnrypted file
	* pme myfile_plain.pdf myfile_enc.dat mypassword
* Now decrypt it
	* pme myfile_enc.dat myfile_dec.pdf mypassword
* Finally, verify integrity of decrypted file
	* diff -bwcs --binary myfile_plain.pdf myfile_dec.pdf
> Written with [StackEdit](https://stackedit.io/).

