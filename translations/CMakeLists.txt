FILE(GLOB_RECURSE PO_FILES *.po)

add_translations(installer ${PO_FILES})