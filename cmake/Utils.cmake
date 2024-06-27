function(find_files_in_directories extensions search_dirs result_var)
    set(result_list)

    # Determine if a non-recursive search is requested
    set(non_recursive FALSE)
    if(ARGC GREATER 3)
        list(GET ARGV 3 non_recursive)
    endif()

    # Find all source files
    foreach(dir IN LISTS search_dirs)
        foreach(ext IN LISTS extensions)
            #message("========================== Searching in directory: ${dir}/${search_pattern}${ext}")
            if(non_recursive)
                file(GLOB files "${dir}/*${ext}") # Non-recursive search
            else()
                file(GLOB_RECURSE files "${dir}/**/*${ext}") # Recursive search
            endif()
            list(APPEND result_list ${files})
        endforeach()
    endforeach()

    # Remove duplicates
    list(REMOVE_DUPLICATES result_list)

    # Set result
    set(${result_var} ${result_list} PARENT_SCOPE)
endfunction()

function(get_header_directories header_files result_dirs_var)
    set(dirs_list)

    # Get header directories
    foreach(file IN LISTS header_files)
        get_filename_component(dir ${file} DIRECTORY)
        list(APPEND dirs_list ${dir})
    endforeach()

    # Remove duplicates
    list(REMOVE_DUPLICATES dirs_list)

    # Set result
    set(${result_dirs_var} ${dirs_list} PARENT_SCOPE)
endfunction()

function(print_list title list)
    message("${title}:")
    foreach(item ${list})
        message("- ${item}")
    endforeach()
endfunction()