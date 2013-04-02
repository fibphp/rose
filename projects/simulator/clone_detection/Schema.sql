-- Schema for binary clone detection output

-- An inputvalue is either a pointer or non-pointer value that belongs to an inputset.  Each pointer value has a sequential
-- position in its inputset; similarly for non-pointers.  The sequence for pointers and non-pointers are independent of one
-- another; they compose two separate input value lists within the inputset as mentioned above.
create table semantic_inputvalues (
       id integer,                              -- ID for the inputset; non-unique
       vtype character,                         -- P (pointer) or N (non-pointer)
       pos integer,                             -- position of this inputvalue within an input sequence, per vtype
       val integer                              -- the integer (pointer or non-pointer) value used as input
);

-- An outputvalue is a member of an outputset.  The relative positions of outputvalues within an outputset is unimportant.
create table semantic_outputvalues (
       id integer,                              -- output set to which this value belongs; non-unique
       val integer                              -- value stored in the output set
);

-- A function is the unit of code that is fuzz tested.
create table semantic_functions (
       id integer primary key,                  -- unique function ID
       entry_va integer,                        -- unique starting virtual address within the binary specimen
       funcname text,                           -- name of function if known
       filename text                            -- name of file in which function exists, if known
);

-- Function input/output. One of these is produced each time we fuzz-test a function.
create table semantic_fio (
       func_id integer references semantic_functions,
       inputset_id integer references semantic_inputsets,
       outputset_id integer references semantic_outputsets
);
