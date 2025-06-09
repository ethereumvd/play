use MyDatabase;

CREATE TABLE index_example (
    customer_id INT AUTO_INCREMENT,   -- Auto-incrementing unique ID
    email VARCHAR(100) NOT NULL,      -- Email field
    username VARCHAR(50) NOT NULL,    -- Username field
    phone VARCHAR(20),                -- Phone number (optional)
    PRIMARY KEY (customer_id),        -- Primary key
    UNIQUE (email),                   -- Unique index on email
    UNIQUE (username)                 -- Unique index on username
);

show index from index_example;
