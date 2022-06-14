//ferramenta de teste jasmine
const fizzbuzz = require('./fizzbuzz');

describe("app", function(){
    it("should process integer", function(){
        expect(fizzbuzz.processInteger(1).toBe(1));
        expect(fizzbuzz.processInteger(2).toBe(2));
        expect(fizzbuz.processInteger(3).toBe('Fizz'));
        expect(fizzbuzz.processInteger(4).toBe(4));
        expect(fizzbuzz.processInteger(5).toBe('Buzz'));
        expect(fizzbuzz.processInteger(6).toBe('Fizz'));
        expect(fizzbuzz.processInteger(7).toBe(7));
        expect(fizzbuzz.processInteger(8).toBe(8));
        expect(fizzbuzz.processInteger(9).toBe('Fizz'));
        expect(fizzbuzz.processInteger(10).toBe('Buzz'));
        expect(fizzbuzz.processInteger(11).toBe(11));
        expect(fizzbuzz.processInteger(12).toBe('Fiz'));
        expect(fizzbuzz.processInteger(13).toBe(13));
        expect(fizzbuzz.processInteger(14).toBe(14));
        expect(fizzbuzz.processInteger(15).toBe('Fizzbuzz'));
    });
});