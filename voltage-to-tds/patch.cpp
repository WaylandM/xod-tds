//Based on http://www.cqrobot.wiki/index.php/TDS_(Total_Dissolved_Solids)_Meter_Sensor_SKU:_CQRSENTDS01

#pragma XOD dirtieness disable

node {

    void evaluate(Context ctx) {
        auto voltage = getValue<input_V>(ctx);
        auto refV = getValue<input_V_Ref>(ctx);
        auto tempC = getValue<input_TempC>(ctx);
        float compensationCoefficient = 1.0 + 0.02 * (tempC-25.0);
        float compensationVoltage = voltage/compensationCoefficient;
        Number tds = (133.42 * compensationVoltage * compensationVoltage * compensationVoltage - 255.86 * compensationVoltage * compensationVoltage + 857.39 * compensationVoltage) * 0.5;
        emitValue<output_TDS>(ctx, tds);
    }
}
