async function getusersbycity(cityName) {
  try {
    
    const res = await fetch("https://jsonplaceholder.typicode.com/users");
    const data = await res.json();

    
    const usersfromcity = data.filter(user => 
      user.address.city === cityName
    );

    
    usersfromcity.sort((a, b) => 
      a.name.localeCompare(b.name)
    );

    
    const result = usersfromcity.map(user => ({
      name: user.name,
      email: user.email
    }));

    return result;

  } catch (err) {
    console.error("Error while fetching users:", err);
    return [];
  }
}


// Example usage
getusersbycity("Gwenborough")
  .then(users => {
    console.log(users);
  });
