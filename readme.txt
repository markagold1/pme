Poor Man's Encryption/Decryption Utility

Usage:
    pme <infile> <outfile> <password>

Description:
    <infile>...............input file to be encrypted or decrypted
    <outfile>..............output file
    <password>.............password (key) to encrypt or decrypt with

Example: Encrypt a plain unencrypted pdf file
    pme myfile_plain.pdf myfile_enc.dat mypassword

Example: Decrypt an encrypted file
    pme myfile_enc.dat myfile_dec.pdf mypassword

Example: Verify integrity of decrypted file
    diff -bwcs --binary myfile_plain.pdf myfile_dec.pdf

<< END >>
