ACLOCAL_AMFLAGS = -I m4
SUBDIRS = src/out_dds_unstr src/out_dds_str

install-data-local:
	(cd ${prefix}/lib; \
	    ln -sf libflb_out_dds_unstr.so ./flb-out_dds_unstr.so; \
	    ln -sf libflb_out_dds_str.so ./flb-out_dds_str.so)

uninstall-local:
	(cd ${prefix}/lib; \
	    rm -f flb-out_dds_unstr.so; \
	    rm -f flb-out_dds_str.so)
