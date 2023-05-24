# dependency
* boost
* cpprest

# boost
b2 install --prefix="%output_path%" variant=%build_type% link=static runtime-link=static address-model=64 --with-headers --with-filesystem --with-system --with-date_time --with-regex --with-program_options --with-log
