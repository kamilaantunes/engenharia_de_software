import axios from "axios"

const api = axios.create({
    baseURL: "https://200.134.21.99/ldapauth/service/authenticate"
});

export default api;