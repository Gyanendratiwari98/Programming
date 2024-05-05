import PyPDF2

# List of PDF files to merge
pdfiles = ["1.pdf", "2.pdf"]

# Create a PdfMerger object
merger = PyPDF2.PdfMerger()

# Iterate through each PDF file in the list
for filename in pdfiles:
    # Open the PDF file in read-binary mode
    pdfFile = open(filename, "rb")
    # Create a PdfReader object
    pdfReader = PyPDF2.PdfReader(pdfFile)
    # Append the PdfReader object to the PdfMerger object
    merger.append(pdfReader)
    # Close the PDF file
    pdfFile.close()

# Write the merged PDF to a new file named "merged.pdf"
merger.write("merged.pdf")

