import { Routes, Route } from 'react-router-dom';
import { useLocation, __RouterContext } from 'react-router'
import Login from './pages/Login/login'
import Header from './components/Header/Header';
import ForgotPass from './pages/ForgotPass/ForgotPass';

const Routing = () => {
    return (
        <>
        <Header />
        <Routes>
            <Route path="/" element={<Login />} />
            <Route path="/recuperar-senha" element={<ForgotPass />} />
            {/* <Route path="expenses" element={<Expenses />} /> */}
            {/* <Route path="invoices" element={<Invoices />} /> */}
        </Routes>
        </>
    )
}

export default Routing;